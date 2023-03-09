#ifndef MonsterBuilder_H
#define MonsterBuilder_H
#include <iostream>
#include <string>
#include "MonsterV2.h"
using std::cout;
using std::string;

class MonsterBuilder
{
    public:
        MonsterBuilder():mMonster(nullptr){}
        virtual ~MonsterBuilder(){}
        MonsterV2* getMonster() const {return mMonster;} // 获取组装后的怪物
        virtual void loadTrunk(const string& number) = 0; // 只保留组装怪物的具体步骤函数
        virtual void loadHead(const string& number) = 0;
        virtual void loadLimbs(const string& number) = 0;
    protected:
        MonsterV2 * mMonster; // 怪物基类是构建者的组合物
};
#endif