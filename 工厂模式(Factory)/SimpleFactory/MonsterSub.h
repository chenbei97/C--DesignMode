#ifndef MONSTERSUB_H
#define MONSTERSUB_H
#include "Monster.h"

class UndeadMonster: public Monster
{
    public:
        UndeadMonster(int life,int magic,int attack)
        :Monster(life,magic,attack){}
};
class ElementMonster: public Monster
{
    public:
        ElementMonster(int life,int magic,int attack)
        :Monster(life,magic,attack){}
};
class MechanicMonster: public Monster
{
    public:
        MechanicMonster(int life,int magic,int attack)
        :Monster(life,magic,attack){}
};
#endif
