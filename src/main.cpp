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

	std::cout << "Client: " << clientFactory << std::endl;
	std::cout << "Engine: " << engineFactory << std::endl;
	
	std::cout << "BaseClient: " << g_BaseClient << std::endl;
	std::cout << "EntityList: " << g_EngineClient << std::endl;
	std::cout << "EngineClient: " << g_EngineClient << std::endl;
	std::cout << "ModelInfo: " << g_ModelInfo << std::endl;
	std::cout << "GameEventMgr: " << g_GameEventMgr << std::endl;
}

void unload(void) {

}