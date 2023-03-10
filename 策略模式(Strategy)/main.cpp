#include "Fighter.h"
#include "Strategy.h"

int main()
{
    Strategy * s1 = new AddLifeStrategy;
    Strategy * s2 = new AddMagicStrategy;

    Fighter * w = new Warrior(200,200);
    Fighter * m = new Mage(100,300);

    w->print();
    w->setStrategy(s1);
    w->useStrategy();
    w->print();

    m->print();
    m->setStrategy(s2);
    m->useStrategy();
    m->print();
    return 0;
}

/*
g++ main.cpp Fighter.cpp -o main
.\main
*/
