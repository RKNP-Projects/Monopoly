#include "Server.h"

Server::Server()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void Server::sBind(int port)
{
	sockaddr_in address;
	address.sin_family= AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	
	bind(sock, (SOCKADDR*)&address, sizeof(address));
};

void Server::sListen()
{
	listen(sock, SOMAXCONN);
}

void Server::sAccept()
{
	SOCKET con = accept(sock, NULL, NULL);
}
