#include "MonsterConstructor.h"
#include "UndeadBuilder.h"
#include "MechanicBuilder.h"
#include "ElementBuilder.h"

int main()
{
    auto mecbuilder = new MechanicBuilder;
    auto director = new MonsterConstructor(mecbuilder);
    auto mec = director->build("1253679201245");

    director->setBuilder(new UndeadBuilder);
    director->build("");

    director->setBuilder(new ElementBuilder);
    director->build("");
    return 0;
}

/*
g++ mainV2.cpp -o mainV2
.\mainV2
*/