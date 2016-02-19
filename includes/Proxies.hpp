#pragma once

RecvVarProxy sequenceProxy = NULL;

void setViewModelSequence(const CRecvProxyData* pDataConst, void* pStruct, void* pOut) {
	CRecvProxyData* pData = const_cast<CRecvProxyData*>(pDataConst);
	CBaseViewModel* pViewModel = (CBaseViewModel*)pStruct;
	if(pViewModel) {
		IClient* pOwner = g_EntityList->getClientFromHandle(pViewModel->getOwner());
		if(pOwner && pOwner->getIndex() == g_EngineClient->getLocalPlayer()) {
			void* pModel = g_ModelInfo->getModel(pViewModel->getModelIndex());
			const char* model = g_ModelInfo->getModelName(pModel);
			int nSequence = pData->value.m_int;

			if (!strcmp(model, "models/weapons/v_knife_butterfly.mdl")) {
				switch (nSequence) {
					case SEQUENCE_DEFAULT_DRAW:
						nSequence = randomInt(SEQUENCE_BUTTERFLY_DRAW, SEQUENCE_BUTTERFLY_DRAW2); break;
					case SEQUENCE_DEFAULT_LOOKAT01:
						nSequence = randomInt(SEQUENCE_BUTTERFLY_LOOKAT01, SEQUENCE_BUTTERFLY_LOOKAT03); break;
					default:
						nSequence++;
				}
			} else if (!strcmp(model, "models/weapons/v_knife_falchion_advanced.mdl")) {
				switch (nSequence) {
					case SEQUENCE_DEFAULT_IDLE2:
						nSequence = SEQUENCE_FALCHION_IDLE1; break;
					case SEQUENCE_DEFAULT_HEAVY_MISS1:
						nSequence = randomInt(SEQUENCE_FALCHION_HEAVY_MISS1, SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP); break;
					case SEQUENCE_DEFAULT_LOOKAT01:
						nSequence = randomInt(SEQUENCE_FALCHION_LOOKAT01, SEQUENCE_FALCHION_LOOKAT02); break;
					case SEQUENCE_DEFAULT_DRAW:
					case SEQUENCE_DEFAULT_IDLE1:
						break;
					default:
						nSequence--;
				}
			} else if (!strcmp(model, "models/weapons/v_knife_push.mdl")) {
				switch (nSequence) {
					case SEQUENCE_DEFAULT_IDLE2:
						nSequence = SEQUENCE_DAGGERS_IDLE1; break;
					case SEQUENCE_DEFAULT_LIGHT_MISS1:
					case SEQUENCE_DEFAULT_LIGHT_MISS2:
						nSequence = randomInt(SEQUENCE_DAGGERS_LIGHT_MISS1, SEQUENCE_DAGGERS_LIGHT_MISS5); break;
					case SEQUENCE_DEFAULT_HEAVY_MISS1:
						nSequence = randomInt(SEQUENCE_DAGGERS_HEAVY_MISS2, SEQUENCE_DAGGERS_HEAVY_MISS1); break;
					case SEQUENCE_DEFAULT_HEAVY_HIT1:
					case SEQUENCE_DEFAULT_HEAVY_BACKSTAB:
					case SEQUENCE_DEFAULT_LOOKAT01:
						nSequence += 3; break;
					case SEQUENCE_DEFAULT_DRAW:
					case SEQUENCE_DEFAULT_IDLE1:
						break;
					default:
						nSequence += 2;
				}
			} else if (!strcmp(model, "models/weapons/v_knife_survival_bowie.mdl")) {
				switch (nSequence) {
					case SEQUENCE_DEFAULT_DRAW:
					case SEQUENCE_DEFAULT_IDLE1:
						break;
					case SEQUENCE_DEFAULT_IDLE2:
						nSequence = SEQUENCE_BOWIE_IDLE1; break;
					default:
						nSequence--;
				}
			}
			pData->value.m_int = nSequence;
		} 
	}
	sequenceProxy(pData, pStruct, pOut);
}