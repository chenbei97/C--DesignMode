#include "MonsterFactory.h"

int main()
{
    MonsterFactory factory;
    Monster * und = factory.createMonster(MonsterType::UnDead);
    Monster * ele = factory.createMonster(MonsterType::Element);
    Monster * mec1 = factory.createMonster(MonsterType::Mechanic);
    Monster * mec2 = MonsterFactory::createMonster(MonsterType::Mechanic);//可以直接创建
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/