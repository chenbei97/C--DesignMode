#ifndef ElementMonsterV1_H
#define ElementMonsterV1_H
#include "MonsterV1.h"

class ElementMonsterV1 : public MonsterV1
{
public:
    virtual void loadTrunk(const string& number) override
    {
        printf("element monster load trunk!\n");
    }
    virtual void loadHead(const string& number) override
    {
        printf("element monster load head!\n");
    }
    virtual void loadLimbs(const string& number) override
    {
        printf("element monster load limbs!\n");
    }
};

#endif