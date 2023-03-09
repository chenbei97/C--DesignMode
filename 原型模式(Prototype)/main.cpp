#include "MechanicMonster.h"
#include "ElementMonster.h"
#include "UndeadMonster.h"

bool isEqual(Monster*m1,Monster*m2)
{
    return (m1->currentLife()==m2->currentLife()) &&
           (m1->currentMagic()==m2->currentMagic()) &&
           (m1->currentAttack()==m2->currentAttack());
}

void global_func1(Monster* monster)
{ // 如果Monster没有clone方法,需要知道monster指向的实际类型才能创建新对象
    Monster * m = nullptr;
    if (dynamic_cast<UndeadMonster*>(monster) != nullptr)
        m = new UndeadMonster(monster->currentLife(),
                              monster->currentMagic(),
                              monster->currentAttack());
    else if (dynamic_cast<MechanicMonster*>(monster) != nullptr)
        m = new MechanicMonster(monster->currentLife(),
                                monster->currentMagic(),
                                monster->currentAttack());
    else if (dynamic_cast<ElementMonster*>(monster) != nullptr)
        m = new ElementMonster(monster->currentLife(),
                               monster->currentMagic(),
                               monster->currentAttack());
    if (m != nullptr)
    {
        // do something...
        m->describe();
        delete m;
    }
}

void global_func2(Monster* monster)
{// 如果Monster有clone方法,不需要知道monster指向的实际类型即可创建新对象
    Monster * m = monster->clone();
    m->describe();
    delete m;
}

int main()
{
    Monster * ele1 = new ElementMonster(1000,200,400);
    Monster * ele2 = ele1->clone();
    printf("ele1 == ele2? %d\n",isEqual(ele1,ele2));

    auto mec = new MechanicMonster(500,100,300);

    global_func1(ele1);
    global_func2(mec);
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/