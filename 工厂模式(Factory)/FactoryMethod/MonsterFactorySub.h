#ifndef MonsterFactorySub_H
#define MonsterFactorySub_H
#include "MonsterFactory.h"
#include "../SimpleFactory/MonsterSub.h"
#include "stdio.h"
class UndeadFactory: public MonsterFactory
{
    public:
        virtual Monster* createMonster () override
        {
            printf("UndeadFactory create an undeadMonster!\n");
            return new UndeadMonster(0,0,0);
        }
};
class ElementFactory: public MonsterFactory
{
    public:
        virtual Monster* createMonster () override
        {
            printf("ElementFactory create an elementMonster!\n");
            return new ElementMonster(0,0,0);
        }
};
class MechanicFactory: public MonsterFactory
{
    public:
        virtual Monster* createMonster () override
        {
            printf("MechanicFactory create a mechanicMonster!\n");
            return new MechanicMonster(0,0,0);
        }
};
#endif