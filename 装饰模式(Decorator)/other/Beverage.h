#ifndef Beverage_H
#define Beverage_H
class Beverage
{
    public:
        virtual int getprice() = 0;
        virtual ~Beverage(){};
};
#endif