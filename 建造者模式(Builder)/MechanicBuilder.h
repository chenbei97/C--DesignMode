#ifndef MechanicBuilder_H
#define MechanicBuilder_H
#include "MonsterBuilder.h"
#include "MechanicMonsterV2.h"

class MechanicBuilder: public MonsterBuilder
{
    public:
        MechanicBuilder() {mMonster = new MechanicMonsterV2;}
        virtual void loadTrunk(const string& number) override
        {
            printf("1) Mechanic Monster is assemble trunk!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadHead(const string& number) override
        {
            printf("2) Mechanic Monster is assemble head!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadLimbs(const string& number) override
        {
            printf("3) Mechanic Monster is assemble limbs!\n");
            // 对 mMonster dosomething...
        }
};
#endif