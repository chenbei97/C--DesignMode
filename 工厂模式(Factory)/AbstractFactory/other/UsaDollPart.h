#ifndef UsaDollPart_H
#define UsaDollPart_H
#include "DollPart.h"

class UsaBody : public Body
{
    public:
        virtual void describe() override
        {
            printf("this is a body created by usa!\n");
        }
};
class UsaClothes : public Clothes
{
    public:
        virtual void describe() override
        {
            printf("this is a cloth created by usa!\n");
        }
};
class UsaShoes : public Shoes
{
    public:
        virtual void describe() override
        {
            printf("this is a shoe created by usa!\n");
        }
};
#endif