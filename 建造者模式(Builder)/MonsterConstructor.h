#ifndef MonsterConstructor_H
#define MonsterConstructor_H
#include "MonsterBuilder.h"

class MonsterConstructor
{
public:
    MonsterConstructor(MonsterBuilder* builder) :mBuilder(builder){}

    void setBuilder(MonsterBuilder* builder) // 组装的步骤可以变化,进一步提供灵活性
    {
        mBuilder = builder;
    }

    MonsterV2 * build(const string& number)
    {
        mBuilder->loadTrunk(number); // 对mBuilder内部的mMonster进行构建
        mBuilder->loadHead(number);
        mBuilder->loadLimbs(number);

        return mBuilder->getMonster(); // 再返回 MonsterV2 => MonsterBulder = > MonsterConstructor
    }
    private:
        MonsterBuilder * mBuilder; // 构建者是指挥者的组合属性
};
#endif