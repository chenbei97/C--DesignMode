#ifndef content_H
#define content_H
#include <string>
using std::string;

class Content
{
public:
    Content(const string&content,double time):
        mContent(content),mCost(time){}
    
    string content() const {return mContent;}
    double cost() const {return mCost;}
private:
    string mContent;
    double mCost;
};
#endif