#ifndef ListCtrl_H
#define ListCtrl_H
#include "Control.h"
class ListCtrl : public Control
{
    public:
        virtual void draw() override
        {
            cout << "draw a ListCtrl from Control\n";
        }
};
#endif