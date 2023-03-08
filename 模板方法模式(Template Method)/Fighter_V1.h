#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>

using std::cout;
using std::endl;

class Fighter_V1
{
protected:
    int mLife; // 生命值
    int mMagic; // 魔法值
    int mAttack; // 攻击力
    virtual bool canUseBurn() = 0;
public:
    Fighter_V1(int life,int magic,int attack):mLife(life),mMagic(magic),mAttack(attack){};
    virtual ~Fighter_V1();
    void burn();//模板方法
private:
    virtual void effect_enemy(){cout<<"effect_enemy..."<<endl;};
    virtual void effect_self(){cout<<"effect_self..."<<endl;};
    void play_effect(){cout<<"paly effect..."<<endl;};
};
Fighter_V1::~Fighter_V1()
{
}

inline void Fighter_V1::burn()
{ // 固定的4个步骤
    if (canUseBurn() == false) {cout<<"can not use burn skills...\n";return;}

    effect_enemy();
    effect_self();
    play_effect();
}
#endif
