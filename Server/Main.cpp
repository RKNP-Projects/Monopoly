#include <iostream>
#include "Server.h"
#include "MySQLManager.h"

int main()
{
    MySQLManager sqlManager;
    Server server;
    server.bindAndListen(8080);
}