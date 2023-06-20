#ifndef SQLITE_RECORD_H
#define SQLITE_RECORD_H
#include "sqlite3.h"
#include <vector>
#include <string>
using namespace std;

struct SRecordInfo
{
    string name;            // 名字
    string company;         // 公司
    string groupName;       // 班组
    string jobs;            // 工种
    string stamp;           // 时间
    int white;              // 是否白名单
    int coat;               // 是否穿反光衣
    int helmet;             // 是否戴安全帽
    string realImg;         // 实时图片

    SRecordInfo()
        : name("")
        , company("")
        , groupName("")
        , jobs("")
        , stamp("")
        , white(0)
        , coat(0)
        , helmet(0)
        , realImg("")
    {
    }
};

class CSqliteRecord
{
public:
    static CSqliteRecord* signle()
    {
        static CSqliteRecord s;
        return &s;
    }

    ~CSqliteRecord();

    bool openRecordDb();
    void closeRecordDb();
    int addRecord(SRecordInfo& info);
    void loadRecordLists(vector<SRecordInfo> &vecWrites);
private:
    CSqliteRecord();
    bool _opened;
    sqlite3* _db;
    string _tableName;
};

#endif // SQLITE_RECORD_H
