#ifndef MONSTER_H
#define MONSTER_H
class Monster
{
    protected:
        int mLife;
        int mMagic;
        int mAttack;
    public:
        Monster(int life,int magic,int attack):mLife(life),mMagic(magic),mAttack(attack){}
        virtual ~Monster(){};
};
#endif