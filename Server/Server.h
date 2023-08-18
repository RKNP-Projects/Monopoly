#include "Connection.h"
#include <map>
#include <thread>
#include <vector>

using std::map;
using std::vector;
using std::thread;

#pragma comment(lib, "Ws2_32.lib")

class Server
{
private:
	SOCKET sock;
	map<SOCKET, Connection*> connections;
	map<SOCKET,thread*> conThreads;

	void handleConnection(SOCKET conSock);

public:
	Server();
	void bindAndListen(int port);
};

