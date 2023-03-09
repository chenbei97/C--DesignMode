#ifndef ChildFactory_H
#define ChildFactory_H
#include "MonsterFactory.h"
#include "stdio.h"
template <typename T>
class ChildFactory : public MonsterFactory
{
    public:
        virtual Monster* createMonster() override
        {
            printf("ChildFactory create a Monster!\n");
            return new T(0,0,0);
        }
};
#endif