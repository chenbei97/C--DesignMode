#ifndef footer_H
#define footer_H
#include <string>
using std::string;

class Footer
{
public:
    Footer(const string&name):mName(name){}
    string name() const {return mName;}
private:
    string mName;
};
#endif