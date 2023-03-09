#ifndef BarbieDoll_H
#define BarbieDoll_H

#include "DollPart.h"

class BarbieDoll
{
    private:
        Body* mBody;
        Clothes* mClothes;
        Shoes* mShoes;
    public:
        BarbieDoll(Body*body,Clothes*clothes,Shoes*shoes)
            :mBody(body),mClothes(clothes),mShoes(shoes){}
        void assemble()
        {
            printf("assemble a barbie doll successful!The doll's info described as follows:\n");
            mBody->describe();
            mClothes->describe();
            mShoes->describe();
        }
};
#endif