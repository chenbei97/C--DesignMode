#ifndef UndeadMonsterV1_H
#define UndeadMonsterV1_H
#include "MonsterV1.h"

class UndeadMonsterV1 : public MonsterV1
{
public:
    virtual void loadTrunk(const string& number) override
    {
        printf("undead monster load trunk!\n");
    }
    virtual void loadHead(const string& number) override
    {
        printf("undead monster load head!\n");
    }
    virtual void loadLimbs(const string& number) override
    {
        printf("undead monster load limbs!\n");
    }
};

#endif