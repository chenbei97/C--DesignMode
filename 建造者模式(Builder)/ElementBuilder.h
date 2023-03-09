#ifndef ElementBuilder_H
#define ElementBuilder_H
#include "MonsterBuilder.h"
#include "ElementMonsterV2.h"

class ElementBuilder: public MonsterBuilder
{
    public:
        ElementBuilder() {mMonster = new ElementMonsterV2;}
        virtual void loadTrunk(const string& number) override
        {
            printf("1) Element Monster is assemble trunk!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadHead(const string& number) override
        {
            printf("2) Element Monster is assemble head!\n");
            // 对 mMonster dosomething...
        }
        virtual void loadLimbs(const string& number) override
        {
            printf("3) Element Monster is assemble limbs!\n");
            // 对 mMonster dosomething...
        }
};
#endif