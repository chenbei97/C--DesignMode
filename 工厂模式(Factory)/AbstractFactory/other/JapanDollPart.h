#ifndef JapanDollPart_H
#define JapanDollPart_H
#include "DollPart.h"

class JapanBody : public Body
{
    public:
        virtual void describe() override
        {
            printf("this is a body created by japan!\n");
        }
};
class JapanClothes : public Clothes
{
    public:
        virtual void describe() override
        {
            printf("this is a cloth created by japan!\n");
        }
};
class JapanShoes : public Shoes
{
    public:
        virtual void describe() override
        {
            printf("this is a shoe created by japan!\n");
        }
};
#endif