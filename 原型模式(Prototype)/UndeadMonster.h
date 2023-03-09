#ifndef UndeadMonster_H
#define UndeadMonster_H
#include "Monster.h"

class UndeadMonster : public Monster
{
public:
    UndeadMonster(int life,int magic,int attack)
        : Monster(life,magic,attack){}
    UndeadMonster(const UndeadMonster& obj) : Monster(obj)
    { 
        printf("UndeadMonster copy constructor is called!\n"); 
        // 涉及指针的复制(深拷贝)需要写好拷贝函数，这里只是为了打印下信息
    }
    virtual Monster* clone() override
    {
        return new UndeadMonster(*this);//触发构造函数
    }
    
};

#endif