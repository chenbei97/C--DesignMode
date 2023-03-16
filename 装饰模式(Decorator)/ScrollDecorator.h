#ifndef ScrollDecorator_H
#define ScrollDecorator_H
#include "ControlDecorator.h"
class ScrollDecorator : public ControlDecorator
{
    public:
        ScrollDecorator(Control*ctrl) : ControlDecorator(ctrl){}
        virtual void draw()
        {
            ControlDecorator::draw(); // <=>mCtrl->draw();保持原有对象的样子
            drawScroll(); // 额外的装饰功能
        }
    private:
        void drawScroll()
        {
            cout<<"scroll is drawed\n";
        }
};
#endif