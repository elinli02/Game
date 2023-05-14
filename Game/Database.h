#pragma once
#include "User.h"
#include <iostream>
#include<Windows.h>
#include<sql.h>
#include<sqltypes.h>
#include<sqlext.h>
#include<string>
using namespace std;
class Database
{
    static Database* instance;
    Database();
    SQLHSTMT hstmt; //result query
    SQLHDBC hdbc; //odbc
    void createCursor();
public:
    Database(Database& d) = delete;
    void operator=(const Database&) = delete;
    static Database* getInstance();
    User* selectInf(int id_user);
    bool insertSet(int id_user, float volume, bool check_distance);
    bool updateVolume(int id_user, float volume);
    bool updateDistance(int id_user, bool check_distance);
};

