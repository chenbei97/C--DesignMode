#ifndef BeverageDecorator_H
#define BeverageDecorator_H
#include "Beverage.h"
class BeverageDecorator: public Beverage
{
    private:
        Beverage * mBeverage;
    public:
        BeverageDecorator(Beverage*b):mBeverage(b){}
        virtual int getprice() override
        {
            return mBeverage->getprice();
        }
};
#endif