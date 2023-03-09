#ifndef ChinaFactory_H
#define ChinaFactory_H

#include "DollFactory.h"
#include "ChinaDollPart.h"

class ChinaFactory : public DollFactory
{
public:
    virtual Body* createBody() override
    {
        return new ChinaBody;
    }
    virtual Shoes* createShoes() override
    {
        return new ChinaShoes;
    }
    virtual Clothes* createClothes() override
    {
        return new ChinaClothes;
    }
};


#endif