#include "SDK.h"
#include "Skins.h"
#include "Proxies.h"
#include "Functions.h"
#include "FrameStageNotify.h"
#include "FireEventClientSide.h"

#include <iostream>
#include <fstream>

void __attribute__ ((constructor)) load(void);
void __attribute__ ((destructor)) unload(void);

void load(void) {
	CreateInterface clientFactory = (CreateInterface)dlsym(dlopen("client_client.so", RTLD_LAZY), "CreateInterface");
	CreateInterface engineFactory = (CreateInterface)dlsym(dlopen("engine_client.so", RTLD_LAZY), "CreateInterface");

	g_BaseClient = (IBaseClient*)clientFactory("VClient017", nullptr); 
	g_EntityList = (IClientList*)clientFactory("VClientEntityList003", nullptr);
	g_EngineClient = (IVEngineClient*)engineFactory("VEngineClient013", nullptr);
	g_ModelInfo = (IVModelInfoClient*)engineFactory("VModelInfoClient004", nullptr);
	g_GameEventMgr = (IGameEventManager2*)engineFactory("GAMEEVENTSMANAGER002", nullptr);

	long** pClientVMT = (long**) g_BaseClient;
	long** pGameEventMgrVMT = (long**) g_GameEventMgr;

	long* pOriginalClientVMT = *pClientVMT;
	long* pOriginalGameEventMgrVMT = *pGameEventMgrVMT;

	size_t clientVMTSize = 0;
	size_t gameEventMgrVMTSize = 0;

	while((long*)pOriginalClientVMT[clientVMTSize]) {
		++clientVMTSize;
	}
	while((long*)pOriginalGameEventMgrVMT[gameEventMgrVMTSize]) {
		++gameEventMgrVMTSize;
	}
	long* pCloneClientVMT = new long[clientVMTSize];
	long* pCloneGameEventMgrVMT = new long[gameEventMgrVMTSize];

	memcpy(pCloneClientVMT, pOriginalClientVMT, (sizeof(long) * clientVMTSize));
	memcpy(pCloneGameEventMgrVMT, pOriginalGameEventMgrVMT, (sizeof(long) * gameEventMgrVMTSize));

	pCloneClientVMT[36] = (long) FrameStageNotifyHook;
	pCloneGameEventMgrVMT[8] = (long) FireEventClientSideHook;

	originalFrameStageNotify = (FrameStageNotify) pOriginalClientVMT[36];
	originalFireEventClientSide = (FireEventClientSide) pOriginalGameEventMgrVMT[8];

	*pClientVMT = pCloneClientVMT;
	*pGameEventMgrVMT = pCloneGameEventMgrVMT;

	setSkinConfig();
	setKillIconConfig();
	for(ClientClass* pClass = g_BaseClient->getAllClasses(); pClass; pClass = pClass->pNext) {
		if(!strcmp(pClass->pNetworkName, "CBaseViewModel")) {
			RecvTable* pClassTable = pClass->pRecvTable;
			for(int i = 0; i < pClassTable->propCount; ++i) {
				RecvProp* pProp = &pClassTable->pProps[i];
				if(!pProp || strcmp(pProp->pVarName, "m_nSequence")) {
					continue;
				}
				sequenceProxy = pProp->proxy;
				pProp->proxy = (RecvVarProxy) setViewModelSequence;
				break;
			}
			break;
		}
	}
}

void unload(void) {

}