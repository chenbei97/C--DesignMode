#include "MountainFactory.h"
#include "TownFactory.h"
#include "SwampFactory.h"

int main()
{
    auto tf = new TownFactory;
    auto tfund = tf->createUndeadMonster();
    auto tfele = tf->createElementMonster();
    auto tfmec = tf->createMechanicMonster();

    auto sf = new SwampFactory;
    auto sfund = sf->createUndeadMonster();
    auto sfele = sf->createElementMonster();
    auto sfmec = sf->createMechanicMonster();

    MonsterFactory * mf = new MountainFactory;
    auto mfund = mf->createUndeadMonster();
    auto mfele = mf->createElementMonster();
    auto mfmec = mf->createMechanicMonster();

    return 0;
}
/*
g++ main.cpp -o main
.\main
*/