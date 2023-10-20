/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-08 15:09:24
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:12:46
 * @FilePath: \CPPDesignMode\策略模式(Strategy)\Strategy.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#ifndef _Strategy_H
#define _Strategy_H

class Strategy
{   
    public:
        virtual ~Strategy(){}
        virtual void useStrategy(Fighter*) = 0;
};

class AddLifeStrategy: public Strategy
{
    public:
        virtual void useStrategy(Fighter* fighter) override
        {
            fighter->addLife(200);
        }
};

class AddMagicStrategy: public Strategy
{
    public:
        virtual void useStrategy(Fighter* fighter) override
        {
            fighter->addMagic(200);
        }
};

/*
    Strategy有useStrategy(Fighter*)方法需要传递Fighter
    Fighter有setStrategy(Strategy*)方法传递Strategy
    Fighter有useStrategy<=>mStrategy->useStrategy(this)<=>this->addLife
    其实就是隔了一层Strategy,来代替直接内部调用成员方法
*/
#endif