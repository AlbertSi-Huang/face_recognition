#ifndef FILECOMMONHELPER_H
#define FILECOMMONHELPER_H

#include <string>
#include <vector>
using namespace std;
struct SFaceFeatureInfo
{
    std::string name;   // 姓名
    std::string group;  // 班组
    std::string cell;   // 单位
    std::string jobs;   // 工种
    std::string tick;   //
    std::string tempImg;

    unsigned char* fea;
    SFaceFeatureInfo()
        : name("")
        , group("")
        , cell("")
        , tick("")
        , tempImg("")
    {
        fea = new unsigned char[8192];
    }
    void copyTo(SFaceFeatureInfo info)
    {
        this->name = info.name;
        this->group = info.group;
        this->cell = info.cell;
        this->jobs = info.jobs;
        this->tick = info.tick;
        this->tempImg = info.tempImg;
        memcpy(this->fea,info.fea,8192);
    }
    ~SFaceFeatureInfo(){

//        delete fea;
    }
};

class CFileCommonHelper
{
public:
    static bool pathExist(string dirPath);
    static bool fileExist(string filePath);
    static string getCurrentPath();
    static void getFileNames(string path, vector<string>& files,vector<string>& fileNames);
    static bool createDir(string dirPath);

    // 获取不带路径文件名
    static string getNoPathFile(string fullPathFile);
    // 从文件名提取不带后辍文件名
    static string getOnlyFileName(string fileName);
    //获取文件后辍名
    static string getFileNoName(string fileName);

    //分割字符串
    static vector<string> splitString(const string& str, const string& delim);

    static std::string stringToUTF8(const std::string& str);
    static std::string UTF8ToString(const std::string& str);
};


#endif // FILECOMMONHELPER_H
