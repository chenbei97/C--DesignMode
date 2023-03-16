#ifndef AddBubble_H
#define AddBubble_H
#include "BeverageDecorator.h"
class AddBubble: public BeverageDecorator
{
    public:
        AddBubble(Beverage*b):BeverageDecorator(b){}
        virtual int getprice() override
        {
            return BeverageDecorator::getprice()+2; // 珍珠加2元
        }
};
#endif