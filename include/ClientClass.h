#pragma once

class ClientClass {
private:
	char pad[0x8];
public:
	char* pNetworkName;
	RecvTable* pRecvTable;
	ClientClass* pNext;
	int classID;
};