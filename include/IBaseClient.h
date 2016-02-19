#pragma once

class IBaseClient {
public:
	inline ClientClass* getAllClasses() {
		return callVirtualFunc<ClientClass* (__attribute__ ((thiscall)) *) (void*)>(this, 8)(this);
	}
};