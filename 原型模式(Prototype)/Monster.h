#ifndef Monster_H
#define Monster_H
#include "stdio.h"

class Monster
{
    protected:
        int mlife;
        int mmagic;
        int mattack;
    public:
        Monster(int life,int magic,int attack)
            :mlife(life),mmagic(magic),mattack(attack){}
        virtual ~Monster(){};
        int currentLife(){return mlife;}
        int currentMagic(){return mmagic;}
        int currentAttack(){return mattack;};
        void describe()
        {
            printf("life = %d, magic = %d, attack = %d\n",currentLife(),currentMagic(),currentAttack());
        }
    public:
        virtual Monster* clone() = 0; // 需要子类完成克隆事项
};
#endif