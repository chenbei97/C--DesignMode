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