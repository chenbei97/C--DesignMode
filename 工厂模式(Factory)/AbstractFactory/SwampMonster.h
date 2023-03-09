#ifndef SwampMonster_H
#define SwampMonster_H
#include "../SimpleFactory/Monster.h"
#include "stdio.h"
class SwampUndead:public Monster
{
    public:
        SwampUndead(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Swamp Undead is created!\n");}
};
class SwampElement:public Monster
{
    public:
        SwampElement(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Swamp Element is created!\n");}
};
class SwampMechanic:public Monster
{
    public:
        SwampMechanic(int life,int magic,int attack)
        :Monster(life,magic,attack){printf("Swamp Mechanic is created!\n");}
};
#endif