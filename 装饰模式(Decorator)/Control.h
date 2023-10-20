/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-08 15:09:24
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:18:32
 * @FilePath: \CPPDesignMode\装饰模式(Decorator)\Control.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#ifndef Control_H
#define Control_H
#include <iostream>
using std::cout;

class Control
{
    public:
        virtual void draw() = 0; //可以绘制自身
        virtual ~Control(){}
};

#endif