#include "FighterMonster.h"

int main()
{
    V1::Fighter * f1 = new V1::Fighter();
    f1->kill(new V1::Undead());
    f1->kill(new V1::Element());
    f1->kill(new V1::Mechanic());

    V2::Fighter * f2 = new V2::Fighter();
    f2->kill(new V2::Undead());
    f2->kill(new V2::Element());
    f2->kill(new V2::Mechanic());
    return 0;
}

/*
g++ FighterMonster.cpp -o FighterMonster
.\FighterMonster
*/
