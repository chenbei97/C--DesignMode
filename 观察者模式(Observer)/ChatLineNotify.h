#ifndef ChatLineNotify_H
#define ChatLineNotify_H
#include "Notify.h"
#include <map>
#include <list>
using std::map;
using std::list;

class ChatLineNotify : public Notify
{
    private:
        map<int,list<Fighter*>> mFamilyList;
    public:
        virtual void addToList(Fighter*fighter) override;
        virtual void removeFromList(Fighter*fighter) override;
        virtual void notify(Fighter*fighter,const string& info) override;
};
#endif