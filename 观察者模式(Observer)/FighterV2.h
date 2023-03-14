#ifndef FighterV2_H
#define FighterV2_H
#include <string>
using std::string;
#include "Notify.h" // Notify.h包含FighterV2.h,那么FighterV2.h就不能包含Notify.h,二者居其一都不会出错
//class Notify; // 包含或者前向声明均可,最保险的做法是2个都使用前向声明不使用包含头文件

class Fighter
{
    private:
        int mId;
        string mName;
        int mFamilyId = -1;
    public:
        virtual ~Fighter(){}
        Fighter(int id,string name):mId(id),mName(name){}
        void setFamilyId(int id){mFamilyId=id;}
        int getFamilyId()const{return mFamilyId;}
        int id()const {return mId;}
        void setId(int id) {mId=id;}
        void speak(Notify*notifier,const string& info);// Notify是抽象类不可inline
        void notify(Fighter*fighter,const string& info){
            printf("player '%s' received the info '%s' by player '%s' sended\n",
                fighter->mName.c_str(),info.c_str(),mName.c_str());
        }
};
class Warrior: public Fighter
{
    public:
        Warrior(int id,string name):Fighter(id,name){}
};

class Mage: public Fighter
{
    public:
        Mage(int id,string name):Fighter(id,name){}
};

#endif