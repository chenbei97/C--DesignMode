#ifndef UsaFactory_H
#define UsaFactory_H

#include "DollFactory.h"
#include "UsaDollPart.h"

class UsaFactory : public DollFactory
{
public:
    virtual Body* createBody() override
    {
        return new UsaBody;
    }
    virtual Shoes* createShoes() override
    {
        return new UsaShoes;
    }
    virtual Clothes* createClothes() override
    {
        return new UsaClothes;
    }
};


#endif