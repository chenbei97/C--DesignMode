#include "ElementMonsterV1.h"
#include "UndeadMonsterV1.h"
#include "MechanicMonsterV1.h"

int main()
{
    MonsterV1 * ele = new ElementMonster();
    ele->assemble("1253679201245");
    return 0;
}

/*
g++ mainV1.cpp -o mainV1
.\mainV1
*/