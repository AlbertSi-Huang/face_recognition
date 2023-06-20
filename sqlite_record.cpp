#include "sqlite_record.h"
#include <iostream>
#include "FileCommonHelper.h"
#include "DateTimeHelper.h"


CSqliteRecord::CSqliteRecord()
    :_opened(false)
{}

CSqliteRecord::~CSqliteRecord(){}

bool CSqliteRecord::openRecordDb()
{
    if(_opened)return true;
    string currPath = CFileCommonHelper::getCurrentPath();
    string monPath = CDateTimeHelper::getDateTimeString(3);
    string recordDbPath = currPath + "\\resource\\record\\record.db";
    int nRet = sqlite3_open(recordDbPath.c_str(),&_db);
    if(nRet != SQLITE_OK)
    {
        return false;
    }
    char* errMsg;
    string createTable = "create table if not exists record_" + monPath + "(ID integer primary key autoincrement,name nvarchar(32),company nvarchar(32),"
                                                                   "groupName nvarchar(32),jobs nvarchar(32),stamp nvarchar(32),white tinyint,coat tinyint,helmet tinyint,realImg nvarchar(128));";
    std::cout <<"createTable = " << createTable<<std::endl;
    if(sqlite3_exec(_db,createTable.c_str(),NULL,NULL,&errMsg) != SQLITE_OK)
    {
        std::cout <<"errmsg = " <<errMsg <<std::endl;
        return  false;
    }
    _tableName = monPath;
    _opened = true;
    return true;
}

int CSqliteRecord::addRecord(SRecordInfo& info)
{
    if(!_opened)
    {
        return 0;
    }

    std::string sqlInsert = "insert into record_" + _tableName + "(name,company,groupName,jobs,stamp,white,coat,helmet,realImg) values('" + info.name +"','" + info.company+"','" +
            info.groupName+"','" + info.jobs+"','" + info.stamp+"',"+to_string(info.white)+","+to_string(info.coat)+","+to_string(info.helmet)+",'" + info.realImg + "');";
    char* errMsg;
    if(sqlite3_exec(_db,sqlInsert.c_str(),NULL,NULL,&errMsg) != SQLITE_OK)
    {
        std::cout <<"insert record error:" << errMsg<<std::endl;
        return  0;
    }
    return  1;
}

void CSqliteRecord::loadRecordLists(vector<SRecordInfo> &vecRecord)
{
    if(!_opened)
    {
        return;
    }

    sqlite3_stmt *stat;
    const char *pzTail = NULL;
    std::string sql= "select * from record_" + _tableName +";";
    int res = sqlite3_prepare(_db,sql.c_str(), -1, &stat, &pzTail);
    if (res != SQLITE_OK)
    {
        if(stat)
        {
            sqlite3_finalize(stat);
        }
        return;
    }

    int nColumn = sqlite3_column_count(stat);
    do{
        int r = sqlite3_step(stat);
        if(r == SQLITE_ROW)
        {
            SRecordInfo info;
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
                    info.company = string(v);
                }else if(strcmp(otype,"groupName") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.groupName = string(v);

                }else if(strcmp(otype,"jobs") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.jobs = string(v);
                }
                else if(strcmp(otype,"realImg") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.realImg = string(v);
                }else if(strcmp(otype,"stamp") == 0)
                {
                    const char* v = (const char*)sqlite3_column_text(stat, i);
                    info.stamp = string(v);
                }else if(strcmp(otype,"white") == 0)
                {
                    int nWhite = sqlite3_column_int(stat,i);
                    info.white = nWhite;
                }else if(strcmp(otype,"coat") == 0)
                {
                    int nCoat = sqlite3_column_int(stat,i);
                    info.coat = nCoat;
                }else if(strcmp(otype,"helmet") == 0)
                {
                    int nHelmet = sqlite3_column_int(stat,i);
                    info.helmet = nHelmet;
                }
            }
            vecRecord.push_back(info);
        }else if (r == SQLITE_DONE)
        {
            break;
        }
    }while(true);

}


void CSqliteRecord::closeRecordDb()
{

}
