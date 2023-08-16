#include <iostream>
#include "Server.h"

int main()
{
    Server server;
    server.bindAndListen(8080);
}