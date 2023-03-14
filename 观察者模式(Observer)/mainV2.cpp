#include "ChatLineNotify.h"
#include "FighterV2.h"

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

    Notify * notifier = new ChatLineNotify();

    notifier->addToList(p1);
    notifier->addToList(p2);
    notifier->addToList(p3);
    notifier->addToList(p4);

    p1->speak(notifier,"hello observer!");
    notifier->removeFromList(p2);
    p1->speak(notifier,"hello world!");
    p4->speak(notifier,"my name is zhao");

    return 0;
}

/*
g++ mainV2.cpp ChatLineNotify.cpp -o mainV2
.\mainV2
*/