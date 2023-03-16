#ifndef AddMilk_H
#define AddMilk_H
#include "BeverageDecorator.h"
class AddMilk: public BeverageDecorator
{
    public:
        AddMilk(Beverage*b):BeverageDecorator(b){}
        virtual int getprice() override
        {
            return BeverageDecorator::getprice()+2; // 牛奶加2元
        }
};
#endif