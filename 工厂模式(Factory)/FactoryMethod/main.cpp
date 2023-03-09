#include "MonsterFactorySub.h"
#include "ChildFactory.h"

int main()
{
    MonsterFactory * undF = new UndeadFactory;
    Monster * und1 = undF->createMonster();// 工厂直接创建
    Monster * und2 = global_CreateMonster(undF);//工厂全局函数也可以

    auto eleF = new ElementFactory;
    auto ele = global_CreateMonster(eleF);

    auto mecF = new MechanicFactory;
    auto mec = global_CreateMonster(mecF);

    ChildFactory<UndeadMonster> fac; // 无需配套工厂,怪物类泛型即可
    auto m = fac.createMonster();
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/