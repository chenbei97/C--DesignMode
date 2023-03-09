#ifndef MONSTEFACTORY_H
#define MONSTEFACTORY_H
#include "../SimpleFactory/Monster.h"
class MonsterFactory
{
private:
    /* data */
public:
    virtual Monster* createMonster() = 0;
    virtual ~MonsterFactory(){};
};

// 全局函数,不同工厂创建不同的对象
inline Monster * global_CreateMonster(MonsterFactory*factory)
{
    return factory->createMonster();
}
#endif