#ifndef FileDirector_H
#define FileDirector_H
#include "FileBuilder.h"

class FileDirector
{
    private:
        FileBuilder * mBuilder = nullptr; // 聚合关系
    public:
        FileDirector(FileBuilder*builder):mBuilder(builder){}
        void setBuilder(FileBuilder*builder) {mBuilder = builder;}

        string build(Header*header,const std::vector<Content*>&content,Footer*footer){
            mBuilder->contactHeader(header); // 固定顺序构建
            mBuilder->contactContent(content);
            mBuilder->contactFooter(footer);
            mBuilder->print();
            return mBuilder->report();
        }
};

#endif