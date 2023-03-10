#ifndef ExportTxtFileV1_H
#define ExportTxtFileV1_H
#include <iostream>
#include <sstream>
#include <vector>
#include "header.h"
#include "content.h"
#include "footer.h"
using std::cout;
using std::vector;

class ExportTxtFile
{
    private:
        Header mHeader;
        vector<Content*> mContent;
        Footer mFooter;
    public:
        ExportTxtFile(const Header&header,vector<Content*>content,const Footer&footer)
            :mHeader(header),mContent(content),mFooter(footer){}
        void exportFile()
        {
            string file;
            // 1. 拼接标题
            auto header = "depart: "+mHeader.depart()+" date: "+mHeader.date()+"\n";
            // 2. 拼接内容
            string content;
            for(auto c: mContent)
                content += "content: "+c->content()+
                " cost time: "+std::to_string(c->cost())+" h\n";
            // 3. 拼接结尾
            auto footer = "name: "+mFooter.name() + "\n";    

            file+=header;
            file+=content;
            file+=footer;
            cout<<file;
        }
};
#endif