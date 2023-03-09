#ifndef SwampFactory_H
#define SwampFactory_H
#include "MonsterFactory.h"
#include "SwampMonster.h"
class SwampFactory: public MonsterFactory
{
    public:
        virtual Monster* createUndeadMonster() override
        {
            printf("SwampFactory create an UndeadMonster!\n");
            return new SwampUndead(0,0,0);
        }
        virtual Monster* createElementMonster() override
        {
            printf("SwampFactory create an ElementMonster!\n");
            return new SwampElement(0,0,0);
        }
        virtual Monster* createMechanicMonster() override
        {
            printf("SwampFactory create a MechanicMonster!\n");
            return new SwampMechanic(0,0,0);
        }
};
#endif