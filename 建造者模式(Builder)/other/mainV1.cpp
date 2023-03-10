#include "ExportTxtFileV1.h"
#include "ExportXmlFileV1.h"
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
    vector<Content*> content;
    for(auto c: contents)
    {
        auto [text,cost] = c;
        content.push_back(new Content(text,cost));
    }
    ExportTxtFile * txt = new ExportTxtFile(*header,content,*footer); 
    txt->exportFile();

    ExportXmlFile * xml = new ExportXmlFile(*header,content,*footer);
    xml->exportFile();   
    return 0;
}

/*
g++ mainV1.cpp -o mainV1
.\mainV1
*/