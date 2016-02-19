#pragma once

class IBaseClientDLL;
class IVEngineClient;
class IClientEntityList;
class IVModelInfoClient;
class IGameEventManager2;
class IClientEntity;

IBaseClientDLL* g_BaseClient = nullptr;
IVEngineClient* g_EngineClient = nullptr;
IClientEntityList* g_EntityList = nullptr;
IVModelInfoClient* g_ModelInfo = nullptr;
IGameEventManager2* g_GameEventMgr = nullptr;

#include "Defines.hpp"
#include "interfaces/DataTable.hpp"
#include "interfaces/ClientClass.hpp"
#include "interfaces/IBaseClientDLL.hpp"
#include "interfaces/IVEngineClient.hpp"
#include "interfaces/IVModelInfoClient.hpp"
#include "interfaces/IGameEvents.hpp"
#include "interfaces/IClientList.hpp"
#include "interfaces/IClient.hpp"