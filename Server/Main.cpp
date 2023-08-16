#include <iostream>
#include "Server.h"

int main()
{
    Server server;
    server.sBind(8080);
    server.sListen();
    server.sAccept();
}