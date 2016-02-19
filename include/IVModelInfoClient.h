#pragma once

class IVModelInfoClient {
public:
	inline void* getModel(int index) {
		return callVirtualFunc<void*(__attribute__ ((thiscall)) *)(void*, int)>(this, 1)(this, index);
	}

	inline int getModelIndex(const char* fileName) {
		return callVirtualFunc<int(__attribute__ ((thiscall)) *)(void*, const char*)>(this, 2)(this, fileName);
	}

	inline const char* getModelName(const void* model) {
		return callVirtualFunc<const char*(__attribute__ ((thiscall)) *)(void*, const void*)>(this, 3)(this, model);
	}
};