#pragma once

inline bool applyCustomSkin(CBaseAttributableItem* pWeapon, int weaponIndex) {
	if(g_SkinChangerCfg.find(weaponIndex) == g_SkinChangerCfg.end()) {
		return false;
	}

	EconomyItemCfg item = g_SkinChangerCfg[weaponIndex];
	*pWeapon->getFallbackPaintKit() = item.fallbackPaintKit;
	*pWeapon->getEntityQuality() = item.entityQuality;
	*pWeapon->getFallbackSeed() = item.fallbackSeed;
	*pWeapon->getFallbackStatTrak() = item.fallbackStatTrak;
	*pWeapon->getFallbackWear() = item.fallbackWear;
	if(item.itemDefinitionIndex) {
		*pWeapon->getItemDefinitionIndex() = item.itemDefinitionIndex;
	}
	if(item.customName) {
		snprintf(pWeapon->getCustomName(), 32, "%s", item.customName);
	}
	*pWeapon->getItemIDHigh() = -1;
	return true;
}

inline bool applyCustomModel(CBasePlayer* pLocal, CBaseAttributableItem* pWeapon, int weaponIndex) {
	CBaseViewModel* pViewModel = pLocal->getViewModel();
	if(!pViewModel) {
		return false;
	}	
	long hViewModelWeapon = pViewModel->getWeapon();
	CBaseAttributableItem* pViewModelWeapon = (CBaseAttributableItem*)g_EntityList->getClientFromHandle(hViewModelWeapon);
	if(pViewModelWeapon != pWeapon) {
		return false;
	}
	int viewModelIndex = pViewModel->getModelIndex();
	if(g_ViewModelCfg.find(viewModelIndex) == g_ViewModelCfg.end()) {
		return false;
	}
	pViewModel->setWeaponModel(g_ViewModelCfg[viewModelIndex], pWeapon);
	return true;
}

inline bool applyCustomKillIcon(IGameEvent* pEvent) {
	int userID = pEvent->getInt("attacker");
	if(!userID) {
		return false;
	}
	if(g_EngineClient->getPlayerForUserID(userID) != g_EngineClient->getLocalPlayer()) {
		return false;
	}
	const char* weapon = pEvent->getString("weapon");
	for(auto replacementIcon : g_KillIconCfg) {
		if(!strcmp(weapon, replacementIcon.first)) {
			pEvent->setString("weapon", replacementIcon.second);
			break;
		}
	}
	return true;
}