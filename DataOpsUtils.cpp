#include "DataOpsUtils.h"
#include <stdio.h>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool InsertAUserInfo(string username, string password) {
    sql::Driver *driver = get_driver_instance();
    sql::Connection *con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
    con->setSchema("iWen");
    sql::Statement *stmt = con->createStatement();
    sql::ResultSet *res;
    char buffer [100];
    sprintf(buffer, "INSERT INTO iwen_user_info (username, password, create_date) VALUES (\"%s\", \"%s\", NOW());", username.c_str(), password.c_str());
    string queryCmd = buffer;
    cout << "Query Command: " << queryCmd << endl;
    try {
        res = stmt->executeQuery(queryCmd);
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
            if(e.getErrorCode() == 0) {
                return true;
            } else {
                cout << "# ERR: SQLException in " << __FILE__;
                cout << "(\" << __FUNCTION__ << \") on line " << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                return false;
            }
    }
    return true;
}