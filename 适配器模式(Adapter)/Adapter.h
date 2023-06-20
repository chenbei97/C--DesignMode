/*
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-20 17:06:26
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-06-20 17:25:22
 * @FilePath: \CPPDesignMode\适配器模式(Adapter)\Adapter.h
 * @Description: 适配器模式
 */
#ifndef Adapter_H
#define Adapter_H
#include "stdio.h"

class LogToFile {
    public:
        void readFile(){printf("read file!\n");};
        void writeFile(){printf("write file!\n");};
};

class LogToDB {
    public: 
        virtual void readDB(){printf("read db!\n");};
        virtual void writeDB(){printf("write db!\n");};
};

class LogAdapter : public LogToDB{
    // 注意: 是继承新接口
    private:
        LogToFile * mFile; // 老接口的指针
    public:
        LogAdapter(LogToFile* file):mFile(file){}
        void readDB() override {mFile->readFile();} // 新接口内部调用的老接口
        void writeDB() override {mFile->writeFile();}
};

void test()
{
    LogToFile file;
    LogAdapter ada(&file);
    //printf("----\n");
    ada.readDB();
    ada.writeDB();
}
#endif