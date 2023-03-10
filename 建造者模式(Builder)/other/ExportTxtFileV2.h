#ifndef ExportTxtFileV2_H
#define ExportTxtFileV2_H
#include "FileBuilder.h"

class ExportTxtFile: public FileBuilder
{
    public:
        virtual void contactHeader(Header* header) override
        {// 1. 拼接标题
            auto h = "depart: "+header->depart()+" date: "+header->date()+"\n";
            mDailyReport+=h;
        }
        virtual void contactContent(const std::vector<Content*>& contents) override
        {// 2. 拼接内容
            string content;
            for(auto c: contents)
                content += "content: "+c->content()+
                " cost time: "+std::to_string(c->cost())+" h\n";
            mDailyReport+=content;
        }
        virtual void contactFooter(Footer*footer) override
        {// 3. 拼接结尾
            mDailyReport += "name: "+footer->name() + "\n"; 
        }
};
#endif