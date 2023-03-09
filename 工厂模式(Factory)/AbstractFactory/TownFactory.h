#ifndef TownFactory_H
#define TownFactory_H
#include "MonsterFactory.h"
#include "TownMonster.h"
class TownFactory: public MonsterFactory
{
    public:
        virtual Monster* createUndeadMonster() override
        {
            printf("TownFactory create an UndeadMonster!\n");
            return new TownUndead(0,0,0);
        }
        virtual Monster* createElementMonster() override
        {
            printf("TownFactory create an ElementMonster!\n");
            return new TownElement(0,0,0);
        }
        virtual Monster* createMechanicMonster() override
        {
            printf("TownFactory create a MechanicMonster!\n");
            return new TownMechanic(0,0,0);
        }
};
#endif