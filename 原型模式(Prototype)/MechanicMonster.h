#ifndef MechanicMonster_H
#define MechanicMonster_H
#include "Monster.h"

class MechanicMonster : public Monster
{
public:
    MechanicMonster(int life,int magic,int attack)
        : Monster(life,magic,attack){}
    MechanicMonster(const MechanicMonster& obj) : Monster(obj)
    { 
        printf("MechanicMonster copy constructor is called!\n"); 
        // 涉及指针的复制(深拷贝)需要写好拷贝函数，这里只是为了打印下信息
    }
    virtual Monster* clone() override
    {
        return new MechanicMonster(*this);//触发构造函数
    }
    
};

#endif