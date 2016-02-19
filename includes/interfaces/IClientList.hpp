#pragma once

class IClientList {
public:
	inline IClient* getClient(int index) {
		return callVirtualFunc<IClient*(__attribute__ ((thiscall)) *)(void*, int)>(this, 3)(this, index);
	}

	inline IClient* getClientFromHandle(long handle) {
		return callVirtualFunc<IClient*(__attribute__ ((thiscall)) *)(void*, int)>(this, 4)(this, handle);
	}
};