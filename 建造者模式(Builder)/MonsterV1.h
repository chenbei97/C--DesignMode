#ifndef MonsterV1_H
#define MonsterV1_H
#include <string>
using std::string;

class MonsterV1
{
public:
    virtual ~MonsterV1(){};
    void assemble(const string& number)
    { // number是编号,取出其中的部分字符串用于给躯干头部和四肢标记编号
        loadTrunk(number.substr(4,3));
        loadHead(number.substr(7,3));
        loadLimbs(number.substr(10,3));
    }
protected:
    virtual void loadTrunk(const string& number) = 0;
    virtual void loadHead(const string& number) = 0;
    virtual void loadLimbs(const string& number) = 0;
};

#endif