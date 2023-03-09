#ifndef ChinaDollPart_H
#define ChinaDollPart_H
#include "DollPart.h"

class ChinaBody : public Body
{
    public:
        virtual void describe() override
        {
            printf("this is a body created by china!\n");
        }
};
class ChinaClothes : public Clothes
{
    public:
        virtual void describe() override
        {
            printf("this is a cloth created by china!\n");
        }
};
class ChinaShoes : public Shoes
{
    public:
        virtual void describe() override
        {
            printf("this is a shoe created by china!\n");
        }
};
#endif