#include "config_file.h"
#include "FileCommonHelper.h"

CConfig::~CConfig()
{

}
CConfig::CConfig()
{
    string currPath = CFileCommonHelper::getCurrentPath();
    configFile = currPath + "\\config.ini";
}
LPWSTR CConfig::toUnicode(const char* _str)
{
    LPWSTR _ret;
    int _len = strlen(_str) * 2;

    _ret = new WCHAR[_len];

    MultiByteToWideChar(CP_ACP, 0, _str, -1, _ret, _len);

    return _ret;
}

//获取程序路径
wchar_t* CConfig::GetAppPath(wchar_t *AppPath,int nSize)
{
    int i;
    memset(AppPath,0,nSize);
    GetModuleFileName(NULL,AppPath,nSize);
    for (i = wcslen(AppPath) + 1; i >= 0; i --)
    {
        if (AppPath[i] == '\\')
        {
            break;
        }
    }
    AppPath[i] = 0;
    return AppPath;
}

//不要忘记使用完char*后delete[]释放内存
char* CConfig::wide_Char_To_Multi_Byte(wchar_t* pWCStrKey)
{
    //第一次调用确认转换后单字节字符串的长度，用于开辟空间
    int pSize = WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), NULL, 0, NULL, NULL);
    char* pCStrKey = new char[pSize+1];
    //第二次调用将双字节字符串转换成单字节字符串
    WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), pCStrKey, pSize, NULL, NULL);
    pCStrKey[pSize] = '\0';
    return pCStrKey;
}



string CConfig::getUrl()
{
    return _url;
}

int CConfig::getScore()
{
    return _score;
}
void CConfig::setUrl(string url)
{
    _url = url;
//    wchar_t szTitle[64] = {0};
//    wcsncpy_s(szTitle,toUnicode("Section"),sizeof("Section"));
    char szCharTitle[64] = {0};
    memcpy(szCharTitle,"Section",sizeof ("Section"));


    WritePrivateProfileStringA(szCharTitle,"url",url.c_str(),configFile.c_str());
//    WritePrivateProfileString(szTitle,toUnicode("url"),toUnicode(url.c_str()),toUnicode(configFile.c_str()));
}

void CConfig::setTitle(string Title)
{
    _title = Title;
    wchar_t szTitle[10] = {0};
    wcsncpy_s(szTitle,toUnicode("Section"),sizeof("Section"));
    char szCharTiTle[10] = {0};
    memcpy(szCharTiTle,"Section",sizeof ("Section"));

    WritePrivateProfileStringA(szCharTiTle,"title",Title.c_str(),configFile.c_str());
//    WritePrivateProfileString(szTitle,toUnicode("title"),toUnicode(Title.c_str()),toUnicode(configFile.c_str()));
}

void CConfig::setProName(string pName)
{
    _proName = pName;
    char szCharTiTle[10] = {0};
    memcpy(szCharTiTle,"Section",sizeof ("Section"));

    WritePrivateProfileStringA(szCharTiTle,"proName",pName.c_str(),configFile.c_str());
}

void CConfig::setScore(int score)
{
    char szCharTiTle[10] = {0};
    memcpy(szCharTiTle,"Section",sizeof ("Section"));
    string currPath = CFileCommonHelper::getCurrentPath();
    string configFile = currPath + "\\config.ini";
    char szTmp[64];
    sprintf(szTmp,"%d",score);
    _score = score;
    WritePrivateProfileStringA(szCharTiTle,"score",szTmp,configFile.c_str());
}

void CConfig::setCompany(string company)
{
    _company = company;
    char szCharTiTle[10] = {0};
    memcpy(szCharTiTle,"Section",sizeof ("Section"));

    WritePrivateProfileStringA(szCharTiTle,"company",company.c_str(),configFile.c_str());
}

bool CConfig::initConfig()
{
    char buf[2048] = {0};
    char szCharTiTle[10] = {0};
    memcpy(szCharTiTle,"Section",sizeof ("Section"));
    string currPath = CFileCommonHelper::getCurrentPath();
    string configFile = currPath + "\\config.ini";
    //读取字符串数据
    GetPrivateProfileStringA(szCharTiTle,"url","www.baidu.com",buf,sizeof(buf),configFile.c_str());
    //直接写入字符串数据
    WritePrivateProfileStringA(szCharTiTle,"url",buf,configFile.c_str());
//    char* url = wide_Char_To_Multi_Byte(buf);
    _url = string(buf);

    ZeroMemory(buf,2048);
    //读取字符串数据
    GetPrivateProfileStringA(szCharTiTle,"title","中建三局一公司建筑设计院",buf,sizeof(buf),configFile.c_str());
    //直接写入字符串数据
    WritePrivateProfileStringA(szCharTiTle,"title",buf,configFile.c_str());

    _title = string(buf);

    ZeroMemory(buf,2048);
    //读取字符串数据
    GetPrivateProfileStringA(szCharTiTle,"proName","新江湾-FD地块商办项目",buf,sizeof(buf),configFile.c_str());
    //直接写入字符串数据
    WritePrivateProfileStringA(szCharTiTle,"proName",buf,configFile.c_str());
    _proName = string(buf);

    ZeroMemory(buf,2048);
    //读取字符串数据
    GetPrivateProfileStringA(szCharTiTle,"company","中建三局一公司",buf,sizeof(buf),configFile.c_str());
    //直接写入字符串数据
    WritePrivateProfileStringA(szCharTiTle,"company",buf,configFile.c_str());
    _company = string(buf);

    //读取整形数据
    int score = GetPrivateProfileIntA(szCharTiTle,"score",75,configFile.c_str());
    //写入整形数据
    char szTmp[64];
    sprintf(szTmp,"%d",score);
    WritePrivateProfileStringA(szCharTiTle,"score",szTmp,configFile.c_str());
    _score = score;

    return true;
}


