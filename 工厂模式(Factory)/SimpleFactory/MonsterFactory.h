#ifndef MONSTERFACTORY
#define MONSTERFACTORY
#include "MonsterSub.h"
#include "stdio.h"

class MonsterFactory
{  
public:
    enum class MonsterType {UnDead,Element,Mechanic};
    static Monster* createMonster(MonsterType type)
    {
        Monster * monster = nullptr;
        switch (type)
        {
            case MonsterType::UnDead:
                monster = new UndeadMonster(0,0,0);
                printf("UndeadMonster is created!\n");
                break;
            case MonsterType::Element:
                monster = new ElementMonster(0,0,0);
                printf("ElementMonster is created!\n");
                break;
            case MonsterType::Mechanic:
                monster = new MechanicMonster(0,0,0);
                printf("MechanicMonster is created!\n");
                break;
        }
        return monster;
    }
};
typedef MonsterFactory::MonsterType MonsterType;
#endif