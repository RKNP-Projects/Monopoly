#include "MySQLManager.h"

MySQLManager::MySQLManager() {
    try
    {
        // REMEMBER: each thread must create its own driver & connection
        driver = get_driver_instance();
        con = driver->connect(SQL_SERVER_IP, SQL_USERNAME, SQL_PASSWORD);
        con->setSchema("monopoly");
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to sql server. Error message: " << e.what() << std::endl;
        exit(1);
    }
}