#pragma once

class IClient;
class IBaseClient;
class IVEngineClient;
class IClientList;
class IVModelInfoClient;
class IGameEventManager2;
class IClientEntity;

IBaseClient* g_BaseClient = nullptr;
IVEngineClient* g_EngineClient = nullptr;
IClientList* g_EntityList = nullptr;
IVModelInfoClient* g_ModelInfo = nullptr;
IGameEventManager2* g_GameEventMgr = nullptr;

#include "Defines.h"
#include "DataTable.h"
#include "ClientClass.h"
#include "IBaseClient.h"
#include "IVEngineClient.h"
#include "IVModelInfoClient.h"
#include "IGameEvents.h"
#include "IClientList.h"
#include "IClient.h"