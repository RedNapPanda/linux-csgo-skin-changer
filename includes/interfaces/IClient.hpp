#pragma once

#define m_nIndex					0x64

#define m_nModelIndex				0x254
#define m_hWeapon					0x29B8
#define m_hOwner					0x29BC

#define m_lifeState					0x25B
#define m_hMyWeapons				0x2DE8
#define m_hViewModel				0x32EC

#define m_AttributeManager			0x2D70
#define m_Item						0x40
#define m_itemDefinitionIndex		0x1D0
#define m_iItemIDHigh				0x1E8
#define m_iAccountID				0x1F0
#define m_entityQuality			0x1D4
#define m_customName				0x264
#define m_OriginalOwnerXuidLow		0x3158
#define m_OriginalOwnerXuidHigh		0x315C
#define m_fallbackPaintKit			0x3160
#define m_fallbackSeed				0x3164
#define m_fallbackWear			0x3168
#define m_fallbackStatTrak			0x316C

class IClient {
public:
	inline int getIndex() {
		return *(int*)((long)this + m_nIndex);
	}
};

class CBaseViewModel : public IClient {
public:
	inline int getModelIndex() {
		return *(int*)((long)this + m_hOwner);
	}

		inline long getOwner() {
			return *(Plong)((long)this + m_hOwner);
		}

		inline long getWeapon() {
			return *(Plong)((long)this + m_hWeapon);
		}

		inline void SetWeaponModel(const char* fileName, IClient* weapon) {
			return callVirtualFunction<void(__attribute__ ((thiscall)) *)(void*, const char*, IClient*)>(this, 242)(this, fileName, weapon);
		}
};

class CBasePlayer : public IClient {
public:
	inline unsigned char getLifeState() {
		return *(unsigned char*)((long)this + m_lifeState);
	}
	inline unsigned int* getWeapons() {
		return (unsigned int*)((long)this + m_hMyWeapons);
	}

	inline CBaseViewModel* getViewModel() {
		return (CBaseViewModel*)g_EntityList->getClientFromHandle(*(long*)(this + m_hViewModel));
	}
};

class CBaseAttributableItem : public IClient {
public:
	inline int* getItemDefinitionIndex() {
		return (int*)((long)this + m_AttributeManager + m_Item + m_itemDefinitionIndex);
	}

	inline int* getItemIDHigh() {
		return (int*)((long)this + m_AttributeManager + m_Item + m_iItemIDHigh);
	}

	inline int* getAccountID() {
		return (int*)((long)this + m_AttributeManager + m_Item + m_iAccountID);
	}

	inline int* getEntityQuality() {
		return (int*)((long)this + m_AttributeManager + m_Item + m_entityQuality);
	}

	inline char* getCustomName() {
		return (char*)((long)this + m_AttributeManager + m_Item + m_customName);
	}

	inline int* getOriginalOwnerXuidLow() {
		return (int*)((long)this + m_OriginalOwnerXuidLow);
	}

	inline int* getOriginalOwnerXuidHigh() {
		return (int*)((long)this + m_OriginalOwnerXuidHigh);
	}

	inline int* getFallbackPaintKit() {
		return (int*)((long)this + m_fallbackPaintKit);
	}

	inline int* getFallbackSeed() {
		return (int*)((long)this + m_fallbackSeed);
	}

	inline float* getFallbackWear() {
		return (float*)((long)this + m_fallbackWear);
	}

	inline int* getFallbackStatTrak() {
		return (int*)((long)this + m_fallbackStatTrak);
	}
};