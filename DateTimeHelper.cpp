#include "DateTimeHelper.h"
#include <time.h>
#include <fstream>

string CDateTimeHelper::getDateTimeString(int nType)
{
    time_t timep;
    time (&timep);
    char tmp[64];
    if(nType == 0)
    {
        strftime(tmp, sizeof(tmp), "%Y%m%d%H%M%S",localtime(&timep) );
    }else if(nType == 1)
    {
        strftime(tmp, sizeof(tmp), "%Y%m%d%H%M",localtime(&timep) );
    }else if(nType == 2)
    {
        // 当天
        strftime(tmp, sizeof(tmp), "%Y%m%d",localtime(&timep) );
    }else if(nType == 3)
    {
        // 当月
        strftime(tmp, sizeof(tmp), "%Y%m",localtime(&timep) );
    }

    return tmp;
}

void CDateTimeHelper::writeSimpleLog(string strMsg)
{
    string fileName = getDateTimeString(2);
    fileName += ".log";
    std::ofstream writerLog(fileName.c_str(), ios::app);
    writerLog << getDateTimeString(0) << ":" << strMsg << endl;
    writerLog.close();
}
