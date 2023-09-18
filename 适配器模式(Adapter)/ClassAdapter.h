#ifndef ClassAdapter_H
#define ClassAdapter_H
#include "ObjectAdapter.h"

class ClassAdapter: public LogToDB, private LogToFile
{
    public:
        void readDB() override {
            printf("class adapter read db!\n");
            readFile(); // 使用的LogToFile的接口,由这个类实现本类
        }
        void writeDB() override {
            printf("class adapter write db!\n");
            writeFile();
        }
};

static void test_clsada()
{
    ClassAdapter * db = new ClassAdapter;
    db->readDB();
    db->writeDB();
}

#endif