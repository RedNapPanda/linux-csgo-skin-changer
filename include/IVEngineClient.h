#pragma once

class IVEngineClient {
public:
	inline bool getPlayerInfo(int index, PlayerInfo* playerInfo) {
		return callVirtualFunc<bool(__attribute__ ((thiscall)) *)(void *, int, PlayerInfo*)>(this, 8)(this, index, playerInfo);
	}

	inline int getPlayerForUserID(int userID) {
		return callVirtualFunc<bool(__attribute__ ((thiscall)) *)(void *, int)>(this, 9)(this, userID);
	}

	inline int getLocalPlayer() {
		return callVirtualFunc<int(__attribute__ ((thiscall)) *)(void *)>(this, 12)(this);
	}
};