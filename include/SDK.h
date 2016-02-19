#pragma once

class IClient;
class IBaseClient;
class IVEngineClient;
class IClientList;
class IVModelInfoClient;
class IGameEventManager2;
class IClientEntity;

IBaseClient* g_BaseClient = NULL;
IVEngineClient* g_EngineClient = NULL;
IClientList* g_EntityList = NULL;
IVModelInfoClient* g_ModelInfo = NULL;
IGameEventManager2* g_GameEventMgr = NULL;

#include "Defines.h"
#include "DataTable.h"
#include "ClientClass.h"
#include "IBaseClient.h"
#include "IVEngineClient.h"
#include "IVModelInfoClient.h"
#include "IGameEvents.h"
#include "IClientList.h"
#include "IClient.h"