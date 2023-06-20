#include "sqlite_white.h"
#include <iostream>

CSqliteWhite::CSqliteWhite()
    :_opened(false)
{

}
void CSqliteWhite::closeWhiteDb()
{
    sqlite3_close(_db);
}

CSqliteWhite::~CSqliteWhite()
{

}

bool CSqliteWhite::openWhiteDb()
{
    if(_opened)return true;
    string currPath = CFileCommonHelper::getCurrentPath();
    string whitePath = currPath + "\\resource\\white\\white.db";
    int nRet = sqlite3_open(whitePath.c_str(),&_db);
    if(nRet == SQLITE_OK)
    {
        char* errMsg;
        std::cout <<"create table"<<std::endl;
        string createTable = "create table if not exists whiteLists(ID integer primary key autoincrement, name nvarchar(32),company nvarchar(32), groupName nvarchar(32),"
                             "tick nvarchar(32),jobs nvarchar(32),tempImg nvarchar(128),recv nvarchar(32), fea blob)";
        if(sqlite3_exec(_db,createTable.c_str(), NULL, NULL,&errMsg)!=SQLITE_OK)
        {
            std::cout <<"errmsg = " <<errMsg<<std::endl;
            return false;
        }

        _opened = true;
        return true;
    }
    return false;
}

void CSqliteWhite::loadWhiteLists(vector<SFaceFeatureInfo> &vecWrites)
{
    if(!_opened)return;

    sqlite3_stmt *stat;
    const char *pzTail = NULL;
    int res = sqlite3_prepare(_db, "select * from whiteLists;", -1, &stat, &pzTail);
    if (res != SQLITE_OK)
    {
        if(stat)
        {
            sqlite3_finalize(stat);
        }
        return;
    }

    int nColumn = sqlite3_column_count(stat);
    cout << "总的列数:" << nColumn << endl;
    do{
        int r = sqlite3_step(stat);
        if(r == SQLITE_ROW)
        {
            SFaceFeatureInfo info;
            for (int i = 0; i < nColumn; ++i)
            {
                int vtype = sqlite3_column_type(stat, i);
                const char* otype = sqlite3_column_origin_name(stat, i);
                if(strcmp(otype,"name") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.name = string(v);
                }else if(strcmp(otype,"company") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.cell = string(v);
                }else if(strcmp(otype,"groupName") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.group = string(v);

                }else if(strcmp(otype,"fea") == 0)
                {
                    const void* piblob = sqlite3_column_blob(stat, i);
                    memcpy(info.fea,piblob,8192);
                }else if(strcmp(otype,"tempImg") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.tempImg = string(v);
                }else if(strcmp(otype,"tick") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.tick = string(v);
                }else if(strcmp(otype,"jobs") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.jobs = string(v);
                }
            }
            vecWrites.push_back(info);
        }else if (r == SQLITE_DONE)
        {
            break;
        }
    }while(true);

}


void CSqliteWhite::addLists(SFaceFeatureInfo& info)
{
    if(!_opened)
    {
        return ;
    }
    sqlite3_stmt *stat;
    const char *pzTail = NULL;
    std::string sqlInsert = "insert into whiteLists(name,company,groupName,tick,jobs,tempImg,fea) values('" +
            info.name +"','" + info.cell + "','" + info.group + "','" + info.tick + "','"+info.jobs + "','"+info.tempImg +"',?);";
    std::cout << "sqlInsert = " << sqlInsert<<std::endl;
    int result =  sqlite3_prepare(_db, (const char*)sqlInsert.c_str(), -1, &stat, &pzTail);
    if(!result && stat)
    {
        result = sqlite3_bind_blob(stat, 1, info.fea, 8192, NULL);
        std::cout <<"bind blod = " <<result <<std::endl;

        sqlite3_step(stat);
        sqlite3_finalize(stat);
    }else{
        std::cout << "prepare error" <<std::endl;
        cout << "sqlite3_prepare failed!  " << sqlite3_errmsg(_db) << endl;
    }
}


