#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H
#include <string>
#include <vector>
using namespace std;
class CDateTimeHelper
{
public:
    static string getDateTimeString(int nType = 0);
    static void writeSimpleLog(string strMsg);
};

#endif // DATETIMEHELPER_H
