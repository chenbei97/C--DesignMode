#ifndef MountainMonster_H
#define MountainMonster_H
#include "../SimpleFactory/Monster.h"
#include "stdio.h"
class MountainUndead:public Monster
{
    public:
        MountainUndead(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Mountain Undead is created!\n");}
};
class MountainElement:public Monster
{
    public:
        MountainElement(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Mountain Element is created!\n");}
};
class MountainMechanic:public Monster
{
    public:
        MountainMechanic(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Mountain Mechanic is created!\n");}
};
#endif