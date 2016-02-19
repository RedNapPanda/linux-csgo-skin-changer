#include "SDK.h"
#include "Skins.h"
#include "Proxies.h"
#include "Functions.h"
#include "FrameStageNotify.h"
#include "FireEventClientSide.h"

void __attribute__ ((constructor)) load(void);
void __attribute__ ((destructor)) unload(void);

void load(void) {
	printf("K It Worked");
// 	CreateInterface clientFactory = (CreateInterface)dlsym(dlopen("client_client.so", RTLD_LAZY), "CreateInterface");
// 	CreateInterface engineFactory = (CreateInterface)dlsym(dlopen("engine_client.so", RTLD_LAZY), "CreateInterface");

// 	g_BaseClient = (IBaseClient*)clientFactory("VClient017", NULL); 
// 	g_EntityList = (IClientList*)clientFactory("VClientEntityList003", NULL);
// 	g_EngineClient = (IVEngineClient*)engineFactory("VEngineClient013", NULL);
// 	g_ModelInfo = (IVModelInfoClient*)engineFactory("VModelInfoClient004", NULL);
// 	g_GameEventMgr = (IGameEventManager2*)engineFactory("GAMEEVENTSMANAGER002", NULL);

	// printf("Client: %p", clientFactory);
	// printf("Engine: %p", engineFactory);

	// printf("BaseClient: %p", g_BaseClient);
	// printf("EntityList: %p", g_EntityList);
	// printf("EngineClient: %p", g_EngineClient);
	// printf("ModelInfo: %p", g_ModelInfo);
	// printf("GameEventMgr: %p", g_GameEventMgr);
}

void unload(void) {

}