#ifndef MonsterFactory_H
#define MonsterFactory_H
#include "../SimpleFactory/Monster.h"
class MonsterFactory
{
public: // 继承的工厂子类都可以创建全部的怪物对象,每个工厂子类是一类场景
    virtual Monster* createUndeadMonster() = 0;
    virtual Monster* createElementMonster() = 0;
    virtual Monster* createMechanicMonster() = 0;
    virtual ~MonsterFactory(){};
};
#endif