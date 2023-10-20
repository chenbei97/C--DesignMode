/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-06-08 15:09:24
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:18:57
 * @FilePath: \CPPDesignMode\装饰模式(Decorator)\ControlDecorator.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#ifndef ControlDecorator_H
#define ControlDecorator_H
#include "Control.h"
class ControlDecorator: public Control // 被装饰以后还是Control类,继承
{
    private:
        Control * mCtrl; // 被装饰的对象指针,组合关系
    public:
        ControlDecorator(Control*ctrl):mCtrl(ctrl) {}
        virtual void draw() override
        {
            mCtrl->draw(); // mCtrl本来的样子
            //.... 这里可以写增加mCtrl功能的代码,就实现了装饰效果
            // drawBorder(); drawScrollBar();
            // 或者子类继续继承ControlDecorator也可,对draw()重实现
        }
};

/*
    和代理模式一样，继承基类，构造函数有基类，覆写基类成员函数
*/
#endif