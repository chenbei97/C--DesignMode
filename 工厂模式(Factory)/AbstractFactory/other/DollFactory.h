#ifndef DollFactory_H
#define DollFactory_H
#include "DollPart.h"

class DollFactory
{
    public:
        virtual Body* createBody() = 0;
        virtual Clothes* createClothes() = 0;
        virtual Shoes* createShoes() = 0;
        virtual ~DollFactory(){}
};
#endif