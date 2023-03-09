#ifndef MechanicMonsterV1_H
#define MechanicMonsterV1_H
#include "MonsterV1.h"

class MechanicMonsterV1 : public MonsterV1
{
public:
    virtual void loadTrunk(const string& number) override
    {
        printf("mechanic monster load trunk!\n");
    }
    virtual void loadHead(const string& number) override
    {
        printf("mechanic monster load head!\n");
    }
    virtual void loadLimbs(const string& number) override
    {
        printf("mechanic monster load limbs!\n");
    }
};

#endif