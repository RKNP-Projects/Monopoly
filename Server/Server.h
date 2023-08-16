#include <WinSock2.h>
#include "Connection.h"
#include <vector>

using std::vector;

#pragma comment(lib, "Ws2_32.lib")

class Server
{
private:
	SOCKET sock;
	vector<Connection> connections;

public:
	Server();
	void sBind(int port);
	void sListen();
	void sAccept();

};

