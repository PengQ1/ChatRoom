/*
// Create a table 

CREATE TABLE IF NOT EXISTS `iwen_user_info`(
   `uid` INT UNSIGNED AUTO_INCREMENT,
   `username` VARCHAR(100) NOT NULL,
   `password` VARCHAR(40) NOT NULL,
   `create_date` DATE,
   PRIMARY KEY ( `uid` )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `chat_record`(
   `message_id` INT UNSIGNED AUTO_INCREMENT,
   `username` VARCHAR(100) NOT NULL,
   `message` VARCHAR(300) NOT NULL,
   `time` DATETIME,
   PRIMARY KEY ( `message_id` )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;


// Insert data

INSERT INTO iwen_user_info 
(username, password, create_date) 
VALUES
("pengqi", "ca$hc0w", NOW());

INSERT INTO chat_record 
(username, message, time) 
VALUES
("pengqi", "Today is a good day!", NOW());

INSERT INTO chat_record 
(username, message, time) 
VALUES
("jingwen", "Tomorrow is another day!", NOW());

*/

/*

Compile command:
g++ DataOps.cpp -o DataOps -I /usr/lib/mysql/include/jdbc/  -I /usr/lib/boost/  -L /usr/lib/mysql/lib64/ -lmysqlcppconn

Remember:
Must export a environment variable!!! It takes abount half day to debug on this.
export DYLD_LIBRARY_PATH=/usr/lib/mysql/lib64

*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");

  /* Connect to the MySQL test database */
  con->setSchema("iWen");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT * FROM iwen_user_info");

  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("username") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }
  delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(\" << __FUNCTION__ << \") on line " << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}