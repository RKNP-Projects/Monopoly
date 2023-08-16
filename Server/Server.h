#include "Connection.h"
#include <map>

using std::map;

#pragma comment(lib, "Ws2_32.lib")

class Server
{
private:
	SOCKET sock;
	map<SOCKET, Connection*> connections;

	void handleConnection(SOCKET conSock);

public:
	Server();
	void bindAndListen(int port);
};

