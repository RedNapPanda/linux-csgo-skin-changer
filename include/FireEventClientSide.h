#pragma once

typedef bool(__attribute__ ((thiscall)) *FireEventClientSide)(void*, IGameEvent*);
FireEventClientSide originalFireEventClientSide = NULL;

bool __attribute__ ((fastcall)) FireEventClientSideHook(void* ecx, void* edx, IGameEvent* pEvent) {
	if(!pEvent) {
		return originalFireEventClientSide(ecx, pEvent);
	}
	if(!strcmp(pEvent->getName(), "player_death")) {
		applyCustomKillIcon(pEvent);
	}
	if(!strcmp(pEvent->getName(), "game_newmap")) {
		if(g_ViewModelCfg.size() >= 1) {
			g_ViewModelCfg.clear();
		}
		setModelConfig();
	}
	return originalFireEventClientSide(ecx, pEvent);
}