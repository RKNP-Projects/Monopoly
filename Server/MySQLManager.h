#pragma once

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <vector>

using std::string;

const string SQL_SERVER_IP = "tcp://127.0.0.1:3306";
const string SQL_USERNAME = "MonopolyUser";
const string SQL_PASSWORD = "Rn135792468#";

class MySQLManager
{
    sql::Driver* driver;
    sql::Connection* con;


public:
    MySQLManager();
};