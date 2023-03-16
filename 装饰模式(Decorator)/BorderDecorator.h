#ifndef BorderDecorator_H
#define BorderDecorator_H
#include "ControlDecorator.h"
class BorderDecorator : public ControlDecorator
{
    public:
        BorderDecorator(Control*ctrl) : ControlDecorator(ctrl){}
        virtual void draw()
        {
            ControlDecorator::draw(); // <=>mCtrl->draw();保持原有对象的样子
            drawBorder(); // 额外的装饰功能
        }
    private:
        void drawBorder()
        {
            cout<<"border is drawed\n";
        }
};
#endif