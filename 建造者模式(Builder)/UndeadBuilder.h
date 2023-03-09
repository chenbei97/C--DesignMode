#ifndef UndeadBuilder_H
#define UndeadBuilder_H
#include "MonsterBuilder.h"
#include "UndeadMonsterV2.h"

class UndeadBuilder: public MonsterBuilder
{
    public:
        UndeadBuilder() {mMonster = new UndeadMonsterV2;}
        virtual void loadTrunk(const string& number) override
        {
            printf("1) Undead Monster is assemble trunk!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadHead(const string& number) override
        {
            printf("2) Undead Monster is assemble head!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadLimbs(const string& number) override
        {
            printf("3) Undead Monster is assemble limbs!\n");
            // 对 mMonster dosomething...
        }
};
#endif