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

	std::ofstream dump;
	dump.open("/home/not2excel/tmp/skin-changer.txt");
	dump << "Client: " << clientFactory << std::endl;
	dump << "Engine: " << engineFactory << std::endl;
	
	dump << "BaseClient: " << g_BaseClient << std::endl;
	dump << "EntityList: " << g_EngineClient << std::endl;
	dump << "EngineClient: " << g_EngineClient << std::endl;
	dump << "ModelInfo: " << g_ModelInfo << std::endl;
	dump << "GameEventMgr: " << g_GameEventMgr << std::endl;
	dump.close();
}

void unload(void) {

}