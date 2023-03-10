#ifndef ExportXmlFileV2_H
#define ExportXmlFileV2_H
#include "FileBuilder.h"

class ExportXmlFile: public FileBuilder
{
    public:
        virtual void contactHeader(Header* header) override
        {// 1. 拼接标题
            mDailyReport+="<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            mDailyReport+="<DailyReport>\n"; // 不递进
            mDailyReport+="\t<Header>\n"; // 递进1
            mDailyReport+="\t\t<Depart>"+header->depart()+"</Depart>\n"; // 递进2
            mDailyReport+="\t\t<Date>"+header->date()+"</Date>\n";// 递进2
            mDailyReport+="\t</Header>\n";// 递进1
        }
        virtual void contactContent(const std::vector<Content*>& contents) override
        {// 2. 拼接内容
            mDailyReport+="\t<Body>\n";
            for(auto iter = contents.begin(); iter!=contents.end();++iter)
            {
                mDailyReport+="\t\t<Content>"+(*iter)->content()+"</Content>";
                mDailyReport+=" <CostTime>"+std::to_string((*iter)->cost())+" h</CostTime>\n";
            }
            mDailyReport+="\t</Body>\n";
        }
        virtual void contactFooter(Footer*footer) override
        {// 3. 拼接结尾
            mDailyReport+="\t<Footer>\n";
            mDailyReport+="\t\t<Name>"+footer->name()+"</Name>\n";
            mDailyReport+="\t</Footer>\n";
            
            mDailyReport+="</DailyReport>\n";
        }
};
#endif