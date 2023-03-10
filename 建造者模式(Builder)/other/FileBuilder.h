#ifndef FileBuilder_H
#define FileBuilder_H
#include "header.h"
#include "content.h"
#include "footer.h"
#include <vector>
#include <iostream>

class FileBuilder
{
    public:
        virtual ~FileBuilder(){}
        virtual void contactHeader(Header*) = 0;
        virtual void contactContent(const std::vector<Content*>&) = 0;
        virtual void contactFooter(Footer*) = 0;
        std::string report() const {return mDailyReport;}
        void print() {std::cout<<report();}
    protected:
        std::string mDailyReport;
};
#endif