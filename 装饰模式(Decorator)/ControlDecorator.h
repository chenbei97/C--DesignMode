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
#endif