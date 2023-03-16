#ifndef AddSugar_H
#define AddSugar_H
#include "BeverageDecorator.h"
class AddSugar: public BeverageDecorator
{
    public:
        AddSugar(Beverage*b):BeverageDecorator(b){}
        virtual int getprice() override
        {
            return BeverageDecorator::getprice()+1; // 糖加1元
        }
};
#endif