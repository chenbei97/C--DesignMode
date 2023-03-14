#include "FighterV1.h"

int main()
{
    Fighter * p1 = new Warrior(1,"chen");
    Fighter * p2 = new Warrior(2,"wang");
    Fighter * p3 = new Mage(3,"zhao");
    Fighter * p4 = new Warrior(4,"sun");

    p1->setFamilyId(100);
    p2->setFamilyId(100);
    p3->setFamilyId(100);
    p4->setFamilyId(200);

    FighterLists.push_back(p1);
    FighterLists.push_back(p2);
    FighterLists.push_back(p3);
    FighterLists.push_back(p4);

    p1->speak("hello observer!");
    p4->speak("my name is zhao");

    return 0;
}

/*
g++ mainV1.cpp -o mainV1
.\mainV1
*/