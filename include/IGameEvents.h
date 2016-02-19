#pragma once

class IGameEvent {
public:
	const char* getName() {
		return callVirtualFunc<const char*(__attribute__ ((thiscall)) *)(void*)>(this, 1)(this);
	}

	int getInt(const char* keyName, int iDefault = 0) {
		return callVirtualFunc<int(__attribute__ ((thiscall)) *)(void*, const char*, int)>(this, 6)(this, keyName, iDefault);
	}

	const char* getString(const char* keyName) {
		return callVirtualFunc<const char*(__attribute__ ((thiscall)) *)(void*, const char*, int)>(this, 9)(this, keyName, 0);
	}

	void setString(const char* keyName, const char* value) {
		return callVirtualFunc<void(__attribute__ ((thiscall)) *)(void*, const char*, const char*)>(this, 15)(this, keyName, value);
	}
};

class IGameEventManager2 {
public:
	bool fireEventClientSide(IGameEvent* pEvent) {
		return callVirtualFunc<bool(__attribute__ ((thiscall)) *)(void*, IGameEvent*)>(this, 8)(this, pEvent);
	}
};