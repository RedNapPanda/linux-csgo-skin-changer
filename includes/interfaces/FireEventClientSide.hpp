#pragma once

#include <string.h>

typedef bool(__attribute ((thiscall)) *FireEventClientSide)(void*, IGameEvent*);
FireEventClientSide originalFireEventClientSide = NULL;

bool __attribute ((fastcall)) FireEventClientSideHook(void* ecx, void* edx, IGameEvent* pEvent) {
	if(!pEvent) {
		return originalFireEventClientSide(ecx, pEvent);
	}
	if(!strcmp(pEvent->GetName(), "player_death")) {
		applyCustomKillIcon(pEvent);
	}
	if(!strcmp(pEvent->GetName(), "game_newmap")) {
		if(g_ViewModelCfg.size() >= 1) {
			g_ViewModelCfg.clear();
		}
		setModelConfig();
	}
	return originalFireEventClientSide(ecx, pEvent);
}