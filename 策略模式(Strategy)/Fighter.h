/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-08 15:09:24
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:12:00
 * @FilePath: \CPPDesignMode\策略模式(Strategy)\Fighter.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
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