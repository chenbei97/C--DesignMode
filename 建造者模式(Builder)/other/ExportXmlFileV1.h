#ifndef ExportXmlFileV1_H
#define ExportXmlFileV1_H
#include <iostream>
#include <sstream>
#include <vector>
#include "header.h"
#include "content.h"
#include "footer.h"
using std::cout;
using std::vector;
class ExportXmlFile
{
    private:
        Header mHeader;
        vector<Content*> mContent;
        Footer mFooter;
    public:
        ExportXmlFile(const Header&header,vector<Content*>content,const Footer&footer)
            :mHeader(header),mContent(content),mFooter(footer){}
        void exportFile()
        {
            string file;

            file+="<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            file+="<DailyReport>\n"; // 不递进

            // 1. 拼接标题
            file+="\t<Header>\n"; // 递进1
            file+="\t\t<Depart>"+mHeader.depart()+"</Depart>\n"; // 递进2
            file+="\t\t<Date>"+mHeader.date()+"</Date>\n";// 递进2
            file+="\t</Header>\n";// 递进1
            // 2. 拼接内容
            file+="\t<Body>\n";
            for(auto iter = mContent.begin(); iter!=mContent.end();++iter)
            {
                file+="\t\t<Content>"+(*iter)->content()+"</Content>";
                file+=" <CostTime>"+std::to_string((*iter)->cost())+" h</CostTime>\n";
            }
            file+="\t</Body>\n";
            // 3. 拼接结尾
            file+="\t<Footer>\n";
            file+="\t\t<Name>"+mFooter.name()+"</Name>\n";
            file+="\t</Footer>\n";
            
            file+="</DailyReport>\n";

            cout<<file;
        }
};
#endif