#pragma once

struct RecvProp;

struct DVariant {
	union {
		float m_float;
		long m_int;
		char* pData;
		float vector[3];
		uint64_t m_int64;
	};

	int type;
};

struct CRecvProxyData {
	const RecvProp* pRecvProp;
	DVariant value;
	int iElement;
	int objectID;
};

struct RecvTable {
public:
	RecvProp* pProps;
	int propCount;
	void* pDecoder;
	char* pNetTableName;
private:
	char pad[2];
};

typedef void(__attribute__ ((cdecl)) *RecvVarProxy)(const CRecvProxyData*, void*, void*);

struct RecvProp {
	char* pVarName;
	int recvType;
	int flags;
	int stringBufferSize;
	bool bInsideArray;
	const void* pExtraData;
	RecvProp* pArrayProp;
	void* arrayLengthProxy;
	RecvVarProxy proxy;
	void* dataTableProxy;
	RecvTable* pDataTable;
	int offset;
	int elementStride;
	int elementCount;
	const char* pParentArrayPropName;
};