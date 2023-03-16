#ifndef FruitBeverage_H
#define FruitBeverage_H
#include "Beverage.h"
class FruitBeverage:public Beverage
{
    public:
        virtual int getprice() override {return 10;} // 普通饮料10元
};
#endif