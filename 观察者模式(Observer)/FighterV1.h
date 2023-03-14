#ifndef FighterV1_H
#define FighterV1_H
#include <string>
#include <list>
using std::string;
using std::list;

class Fighter;
list<Fighter*> FighterLists; // 全局容器,存储所有玩家信息

class Fighter
{
    private:
        int mId;
        string mName;
        int mFamilyId = -1;
    public:
        Fighter(int id,string name):mId(id),mName(name){}
        void setFamilyId(int id){mFamilyId=id;}
        void speak(const string& info);
        virtual ~Fighter(){}
    private:
        void notify(Fighter*,const string& info);
};

inline void Fighter::notify(Fighter*fighter,const string& info)
{
    printf("player '%s' received the info '%s' by player '%s' sended\n",
        fighter->mName.c_str(),info.c_str(),mName.c_str());
}

inline void Fighter::speak(const string&info)
{
    if (mFamilyId != -1)
    {
        for(auto fighter:FighterLists)
        {
            if (fighter->mFamilyId == mFamilyId 
                && fighter->mId != mId) // 不需要通知自己
            {
                notify(fighter,info);
            }
        }
    }
}

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