#pragma once

struct EconomyItemCfg {
	int itemDefinitionIndex = 0;
	int fallbackPaintKit = 0;
	int fallbackSeed = 0;
	int fallbackStatTrak = -1;
	int entityQuality = 4;
	char* customName = nullptr;
	float fallbackWear = 0.1f;
};

std::unordered_map<int, EconomyItemCfg> g_SkinChangerCfg;
std::unordered_map<int, const char*> g_ViewModelCfg;
std::unordered_map<const char*, const char*> g_KillIconCfg;

inline void setSkinConfig() {
	// StatTrak™ AWP | Dragon Lore
	g_SkinChangerCfg[WEAPON_AWP].fallbackPaintKit = 344;
	g_SkinChangerCfg[WEAPON_AWP].fallbackWear = 0.00000001f;
	g_SkinChangerCfg[WEAPON_AWP].fallbackStatTrak = 1337;

	// Valve AK-47 | Redline
	g_SkinChangerCfg[WEAPON_AK47].fallbackPaintKit = 282;
	g_SkinChangerCfg[WEAPON_AK47].entityQuality = 6;

	// Souvenir M4A4 | Howl
	g_SkinChangerCfg[WEAPON_M4A1].fallbackPaintKit = 309;
	g_SkinChangerCfg[WEAPON_M4A1].entityQuality = 12;

	// Prototype Desert Eagle | Conspiracy
	g_SkinChangerCfg[WEAPON_DEAGLE].fallbackPaintKit = 351;
	g_SkinChangerCfg[WEAPON_DEAGLE].entityQuality = 7;

	// Glock-18 | Fade
	g_SkinChangerCfg[WEAPON_GLOCK].fallbackPaintKit = 38;

	// USP-S | Stainless
	g_SkinChangerCfg[WEAPON_USP_SILENCER].fallbackPaintKit = 277;

	// Karambit | Fade (CT)
	g_SkinChangerCfg[WEAPON_KNIFE].itemDefinitionIndex = WEAPON_KNIFE_KARAMBIT;
	g_SkinChangerCfg[WEAPON_KNIFE].fallbackPaintKit = 38;
	g_SkinChangerCfg[WEAPON_KNIFE].entityQuality = 3;

	// Bowie Knife | Crimson Web (T)
	g_SkinChangerCfg[WEAPON_KNIFE_T].itemDefinitionIndex = WEAPON_KNIFE_SURVIVAL_BOWIE;
	g_SkinChangerCfg[WEAPON_KNIFE_T].fallbackPaintKit = 12;
	g_SkinChangerCfg[WEAPON_KNIFE_T].entityQuality = 3;
}

inline void setModelConfig() {
	int nOriginalKnifeCT = g_ModelInfo->getModelIndex("models/weapons/v_knife_default_ct.mdl");
	int nOriginalKnifeT = g_ModelInfo->getModelIndex("models/weapons/v_knife_default_t.mdl");

	g_ViewModelCfg[nOriginalKnifeCT] = "models/weapons/v_knife_karam.mdl";
	g_ViewModelCfg[nOriginalKnifeT] = "models/weapons/v_knife_survival_bowie.mdl";
}

inline void setKillIconCfg() {
	// Define replacement kill icons. (these only apply to you)
	g_KillIconCfg["knife_default_ct"] = "knife_karambit";
	g_KillIconCfg["knife_t"] = "knife_survival_bowie";
}