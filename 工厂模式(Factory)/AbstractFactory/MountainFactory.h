#ifndef MountainFactory_H
#define MountainFactory_H
#include "MonsterFactory.h"
#include "MountainMonster.h"
class MountainFactory: public MonsterFactory
{
    public:
        virtual Monster* createUndeadMonster() override
        {
            printf("MountainFactory create an UndeadMonster!\n");
            return new MountainUndead(0,0,0);
            
        }
        virtual Monster* createElementMonster() override
        {
            printf("MountainFactory create an ElementMonster!\n");
            return new MountainElement(0,0,0);
        }
        virtual Monster* createMechanicMonster() override
        {
            printf("MountainFactory create a MechanicMonster!\n");
            return new MountainMechanic(0,0,0);
        }
};
#endif