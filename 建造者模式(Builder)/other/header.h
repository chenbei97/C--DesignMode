#ifndef header_H
#define header_H
#include <string>
using std::string;

class Header
{
public:
    Header(const string&depart,const string&date):
        mDepart(depart),mDate(date){}
    string depart() const {return mDepart;}
    string date() const {return mDate;}
private:
    string mDepart;
    string mDate;
};


#endif