#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H
#include <map>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class CConfig{
public:
    static CConfig* signle()
    {
        static CConfig s;
        return &s;
    }
    ~CConfig();

    bool initConfig();

    string getUrl();
    int getScore();

    void setUrl(string url);
    void setScore(int score);


    void setTitle(string Title);
    string getTitle(){return _title;}


    void setProName(string pName);
    string getProName(){return _proName;}

    void setCompany(string company);
    string getCompany(){return _company;}
private:
    CConfig();
    LPWSTR toUnicode(const char* _str);
    wchar_t* GetAppPath(wchar_t *AppPath,int nSize);
    char* wide_Char_To_Multi_Byte(wchar_t* pWCStrKey);

    string _title;
    string _proName;
    string _url;
    int _score;
    string _company;

    string configFile;
};


#endif // CONFIG_FILE_H
