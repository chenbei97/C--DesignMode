#ifndef ElementMonster_H
#define ElementMonster_H
#include "Monster.h"

class ElementMonster : public Monster
{
public:
    ElementMonster(int life,int magic,int attack)
        : Monster(life,magic,attack){}
    ElementMonster(const ElementMonster& obj) : Monster(obj)
    { 
        printf("ElementMonster copy constructor is called!\n"); 
        // 涉及指针的复制(深拷贝)需要写好拷贝函数，这里只是为了打印下信息
    }
    virtual Monster* clone() override
    {
        return new ElementMonster(*this);//触发构造函数
    }
    
};

#endif