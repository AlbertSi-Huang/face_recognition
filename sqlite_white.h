#ifndef SQLITE_WRITE_H
#define SQLITE_WRITE_H
#include "sqlite3.h"
#include "FileCommonHelper.h"
#include <vector>
#include <string>
using namespace std;

class CSqliteWhite
{
public:
    static CSqliteWhite* signle()
    {
        static CSqliteWhite s;
        return &s;
    }
    ~CSqliteWhite();

    bool openWhiteDb();
    void loadWhiteLists(vector<SFaceFeatureInfo>& vecWrites);
    void addLists(SFaceFeatureInfo& info);
    void closeWhiteDb();
private:
    bool _opened;

    CSqliteWhite();
    sqlite3* _db;
};

#endif // SQLITE_WRITE_H
