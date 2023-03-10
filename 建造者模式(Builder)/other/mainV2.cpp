#include "ExportTxtFileV2.h"
#include "ExportXmlFileV2.h"
#include "FileDirector.h"
#include <tuple>
using std::tuple;

string depart = "Technology Center";
string date = "2023/03/10";
string name = "chenbei";
std::vector<tuple<string,double>> contents = {
    std::make_tuple<string,double>("finished task1",1.5),
    std::make_tuple<string,double>("finished task2",2.5),
    std::make_tuple<string,double>("finished task3",3.5),
};

int main()
{
    Header * header = new Header(depart,date);
    Footer * footer = new Footer(name);
    std::vector<Content*> content;
    for(auto c: contents)
    {
        auto [text,cost] = c;
        content.push_back(new Content(text,cost));
    }

    ExportTxtFile * txt = new ExportTxtFile; // FileBuilder的子类方法
    ExportXmlFile * xml = new ExportXmlFile;

    FileDirector * director = new FileDirector(txt);
    director->build(header,content,footer);
    director->setBuilder(xml);
    director->build(header,content,footer);
    return 0;
}

/*
g++ mainV2.cpp -o mainV2
.\mainV2
*/