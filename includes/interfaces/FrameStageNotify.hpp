#pragma once

#include <main.hpp>

typedef void(__attribute__ ((thiscall)) *FrameStageNotify)(void*, ClientFrameStage);
FrameStageNotify originalFrameStageNotify = NULL;

void __attribute__ ((fastcall)) FrameStageNotifyHook(void* ecx, void* edx, ClientFrameStage stage) {
	while(stage == FRAME_NET_UPDATE_POSTDATAUPDATE_START) {
		int localPlayerID = g_EngineClient->getLocalPlayer();
		CBasePlayer* pLocal = (CBasePlayer*) g_EntityList-> getClient(localPlayerID);
		if(!pLocal || pLocal->getLifeState() != LIFE_ALIVE) {
			break;
		}
		unsigned int* hWeapons = pLocal->getWeapons();
		if(!hWeapons) {
			break;
		}
		PlayerInfo localPlayerInfo;
		g_EngineClient->getPlayerInfo(localPlayerID, &localPlayerInfo);
		for(int i = 0; hWeapons[i]; ++i) {
			CBaseAttributableItem* pWeapon = (CBaseAttributableItem*) g_EntityList->getClientFromHandle(hWeapons[i]);
			if(!pWeapon) {
				continue;
			}
			int weaponIndex = *pWeapon->getItemDefinitionIndex();
			applyCustomModel(pLocal, pWeapon, weaponIndex);
			if(localPlayerInfo.xuidLow != *pWeapon->getOriginalOwnerXuidLow()) {
				continue;
			}
			if(localPlayerInfo.xuidHigh != *pWeapon->getOriginalOwnerXuidHigh()) {
				continue;
			}
			applyCustomSkin(pWeapon, weaponIndex);
			*pWeapon->getAccountID() = localPlayerInfo.xuidLow;
		}
		break;
	}
	originalFrameStageNotify(ecx, stage);
}