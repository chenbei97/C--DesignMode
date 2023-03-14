#include "ChatLineNotify.h"
#include "FighterV2.h"

void Fighter::speak(Notify*notifier,const string&info)
{
    notifier->notify(this,info); // 因为Notify是个抽象类,必须在这里给出定义,不可inline
} // 给出Fighter的speak定义

void ChatLineNotify::addToList(Fighter* fighter)
{
    auto id = fighter->getFamilyId();
    if (id != -1)
    {
        auto iter = mFamilyList.find(id);// 找到这个家族
        if (iter != mFamilyList.end()) // 如果有这个家族
        {
            iter->second.push_back(fighter); // 把成员添加进这个家族
        }
        else
        {
            list<Fighter*> tmp; // 创建新家族
            mFamilyList.insert(std::make_pair(id,tmp));//make_pair内部有new的操作
            mFamilyList[id].push_back(fighter);// 把成员添加进新家族
        }
    }
}

void ChatLineNotify::removeFromList(Fighter* fighter)
{
    auto id = fighter->getFamilyId();
    if (id != -1)
    {
        auto iter = mFamilyList.find(id);
        if (iter != mFamilyList.end())
        {
            mFamilyList[id].remove(fighter);
        }
    }
}

void ChatLineNotify::notify(Fighter* fighter,const string&info)
{
    auto id = fighter->getFamilyId();
    if (id != -1)
    {
        auto iter = mFamilyList.find(id);
        if (iter != mFamilyList.end())
        {
            for (auto _fighter : iter->second) // list<Fighter*>
            {
                if (_fighter->id() != fighter->id()) // 不通知自身
                    _fighter->notify(fighter,info);
            }
        }
    }
}