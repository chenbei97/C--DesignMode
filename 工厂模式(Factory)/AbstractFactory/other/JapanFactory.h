#ifndef JapanFactory_H
#define JapanFactory_H

#include "DollFactory.h"
#include "JapanDollPart.h"

class JapanFactory : public DollFactory
{
public:
    virtual Body* createBody() override
    {
        return new JapanBody;
    }
    virtual Shoes* createShoes() override
    {
        return new JapanShoes;
    }
    virtual Clothes* createClothes() override
    {
        return new JapanClothes;
    }
};


#endif