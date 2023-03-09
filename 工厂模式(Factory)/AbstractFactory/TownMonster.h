#ifndef TownMonster_H
#define TownMonster_H
#include "../SimpleFactory/Monster.h"
#include "stdio.h"
class TownUndead:public Monster
{
    public:
        TownUndead(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Town Undead is created!\n");}
};
class TownElement:public Monster
{
    public:
        TownElement(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Town Element is created!\n");}
};
class TownMechanic:public Monster
{
    public:
        TownMechanic(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Town Mechanic is created!\n");}
};
#endif