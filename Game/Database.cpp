#include "Database.h"
Database* Database::instance = nullptr;
Database::Database()
{
    string connection;
    bool error = false;
    SQLHENV henv; //environment
    SQLRETURN retcode; //result status connection
    SQLWCHAR OutConnStr[255]; //result connection
    SQLSMALLINT OutConnStrLen;

    const wchar_t con_line[66] = L"Dsn=DSN_Game;uid=root;server=localhost;database=game_db;port=3306";

    retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
    if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
        retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
        if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
            if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
                SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
                retcode = SQLDriverConnect(
                    hdbc,
                    0,
                    (SQLWCHAR*)con_line,
                    _countof(con_line),
                    OutConnStr,
                    255,
                    &OutConnStrLen,
                    SQL_DRIVER_COMPLETE
                );
                if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO) {
                    error = true;
                }
            }
            else {
                error = true;
            }
        }
        else {
            error = true;
        }
    }
    else {
        error = true;
    }
    if (error) {
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
        SQLFreeHandle(SQL_HANDLE_ENV, henv);
    }
}

void Database::createCursor()
{
    SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
}

Database* Database::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Database();
    }
    return instance;
}

User* Database::selectInf(int id_user)
{
    createCursor();
    SQLINTEGER sId;
    SQLFLOAT sVolume;
    SQLINTEGER sCheckDistance;
    SQLCHAR sName[20];
    SQLLEN cbId, cbVolume, cbCheckDistance, cbName;
    SQLRETURN retcode;
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    wstring query = L"SELECT s.id_user, s.volume, s.check_distance, u.name FROM setting as s LEFT JOIN user as u ON u.id = s.id_user WHERE s.id_user = " + to_wstring(id_user);
    retcode = SQLExecDirect(hstmt, (SQLWCHAR*)query.c_str(), SQL_NTS);
    User* user = nullptr;
    if (retcode == SQL_SUCCESS) {
        retcode = SQLFetch(hstmt);
        if (retcode == SQL_ERROR || retcode == SQL_SUCCESS_WITH_INFO) {
            cout << "An error occurred";
        }
        if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            SQLGetData(hstmt, 1, SQL_C_ULONG, &sId, 0, &cbId);
            SQLGetData(hstmt, 2, SQL_C_DOUBLE, &sVolume, 0, &cbVolume);
            SQLGetData(hstmt, 3, SQL_C_ULONG, &sCheckDistance,0, &cbCheckDistance);
            SQLGetData(hstmt, 4, SQL_C_CHAR, sName, 20 , &cbName);
            string newName((const char*)sName);
            user = new User(sId, newName, sVolume, sCheckDistance);
        }
    }
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    return user;
}

bool Database::insertSet(int id_user, float volume, bool check_distance)
{
    return false;
}

bool Database::updateVolume(int id_user, float volume)
{
    createCursor();
    SQLRETURN retcode;
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    wstring query = L"UPDATE setting SET volume=" + to_wstring(volume) + L" WHERE id_user=" + to_wstring(id_user);
    retcode = SQLExecDirect(hstmt, (SQLWCHAR*)query.c_str(), SQL_NTS);
    return retcode == SQL_SUCCESS;
}

bool Database::updateDistance(int id_user, bool check_distance)
{
    createCursor();
    SQLRETURN retcode;
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    wstring query = L"UPDATE setting SET check_distance=" + to_wstring((int)check_distance)+L" WHERE id_user=" + to_wstring(id_user);
    retcode = SQLExecDirect(hstmt, (SQLWCHAR*)query.c_str(), SQL_NTS);
    return retcode == SQL_SUCCESS;
}
