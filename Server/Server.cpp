#include "Server.h"

Server::Server()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void Server::bindAndListen(int port)
{
	sockaddr_in address;
	address.sin_family= AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	
	bind(sock, (SOCKADDR*)&address, sizeof(address));
	listen(sock, SOMAXCONN);

	while (true)
	{
		SOCKET conSock = accept(sock, NULL, NULL);
		handleConnection(conSock);
	}
};

void Server::handleConnection(SOCKET conSock)
{
	connections[conSock] = new Connection();

	char* buff;
	int dataLen = 3;

	
	while (connections[conSock])
	{
		buff = new char[dataLen+1];
		buff[dataLen] = 0;
		if (!recv(conSock, buff, dataLen, NULL) || WSAGetLastError() == WSAECONNRESET || WSAGetLastError() == WSAENOTSOCK)
			break;
		std::cout << buff << std::endl;
		delete buff;
	}

	std::cout << "connecton is closed" << std::endl;
}
