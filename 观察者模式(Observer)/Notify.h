#ifndef Notify_H
#define Notify_H
#include <string>
using std::string;
//#include "FighterV2.h" // Notify.h包含FighterV2.h,那么FighterV2.h就不能包含Notify.h,二者居其一都不会出错
class Fighter; // 包含或者前向声明均可,最保险的做法是2个都使用前向声明不使用包含头文件

class Notify
{
    public:
        virtual ~Notify(){}
        virtual void addToList(Fighter*)=0;
        virtual void removeFromList(Fighter*)=0;
        virtual void notify(Fighter*,const string&)=0;
};
#endif