#include "FileCommonHelper.h"
#include <io.h>
#include  <direct.h>
#include <fstream>
#include <Windows.h>
#include  <stdio.h>
#include <qtextcodec.h>

bool CFileCommonHelper::pathExist(string dirPath)
{
    if(_access(dirPath.c_str(), 0) == -1)
    {
        return false;
    }
    return true;
}

bool CFileCommonHelper::createDir(string dirPath)
{
    int len = dirPath.length();
    char tmpDirPath[256] = { 0 };
    for (int i = 0; i < len; i++)
    {
        tmpDirPath[i] = dirPath[i];
        if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
        {
            if (_access(tmpDirPath, 0) == -1)
            {
                int ret = _mkdir(tmpDirPath);
                if (ret == -1) return ret;
            }
        }
    }
    return true;
}
string CFileCommonHelper::getCurrentPath()
{
    char   buffer[256];
    getcwd(buffer, 256);
    string str(buffer);
    return str;
}
bool CFileCommonHelper::fileExist(string filePath)
{
    ifstream f(filePath.c_str());
    return f.good();
}



//核心代码
void CFileCommonHelper::getFileNames(string path, vector<string>& files,vector<string>& fileNames)
{
    //文件句柄
    //注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
    intptr_t hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    QTextCodec *code = QTextCodec::codecForName("GB2312");

    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //如果是目录,递归查找
            //如果不是,把文件绝对路径存入vector中
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFileNames(p.assign(path).append("\\").append(fileinfo.name), files,fileNames);
            }
            else
            {
                std::string name = code->fromUnicode(fileinfo.name).data();
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                fileNames.push_back(fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

// 获取不带路径文件名
string CFileCommonHelper::getNoPathFile(string fullPathFile)
{
    string::size_type iPos = fullPathFile.find_last_of('\\') + 1;
    string filename = fullPathFile.substr(iPos, fullPathFile.length() - iPos);
    return filename;
}

// 从文件名提取不带后辍文件名
string CFileCommonHelper::getOnlyFileName(string fileName)
{
    string name = fileName.substr(0, fileName.rfind("."));
    return name;
}

//获取文件后辍名
string CFileCommonHelper::getFileNoName(string fileName)
{
    string suffix_str = fileName.substr(fileName.find_last_of('.') + 1);
    return suffix_str;
}

vector<string> CFileCommonHelper::splitString(const string& str, const string& delim)
{
    vector<string> res;
    if("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[str.length() + 1] ; //不要忘了
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}


std::string CFileCommonHelper::stringToUTF8(const std::string& str){
    int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
        wchar_t* pwBuf = new wchar_t[nwLen + 1];
        ZeroMemory(pwBuf, nwLen * 2 + 2);
        ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
        int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
        char* pBuf = new char[nLen + 1];
        ZeroMemory(pBuf, nLen + 1);
        ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

        std::string strRet(pBuf);

        delete []pwBuf;
        delete []pBuf;
        pwBuf = NULL;
        pBuf  = NULL;

        return strRet;
}

std::string CFileCommonHelper::UTF8ToString(const std::string& str){
    int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        wchar_t* pwBuf = new wchar_t[nwLen + 1];
        memset(pwBuf, 0, nwLen * 2 + 2);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);
        int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
        char* pBuf = new char[nLen + 1];
        memset(pBuf, 0, nLen + 1);
        WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

        std::string strRet = pBuf;

        delete []pBuf;
        delete []pwBuf;
        pBuf = NULL;
        pwBuf = NULL;

        return strRet;
}
