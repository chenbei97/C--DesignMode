#ifndef _Fighter_H
#define _Fighter_H
#include "stdio.h"

class Strategy; 

class Fighter
{
    protected:
        int mlife;
        int mmagic;
    private:
        Strategy * mStrategy = nullptr;
    public:
        void addLife(int life){mlife+=life;};
        void addMagic(int magic){mmagic+=magic;};
        void print(){printf("life = %d, magic = %d\n",mlife,mmagic);};
        void setStrategy(Strategy*strategy){mStrategy = strategy;};
        // void useStrategy(){mStrategy->useStrategy(this);};
        
        // void addLife(int life);
        // void addMagic(int magic);
        // void print();
        // void setStrategy(Strategy*strategy);
        void useStrategy();
        
        explicit Fighter(int life,int magic):mlife(life),mmagic(magic){}
        virtual ~Fighter(){}
};

class Warrior: public Fighter
{
    public:
        Warrior(int life,int magic):Fighter(life,magic){}
};

class Mage: public Fighter
{
    public:
        Mage(int life,int magic):Fighter(life,magic){}
};
#endif