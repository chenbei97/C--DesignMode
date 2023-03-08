#include <iostream>

using std::cout;
using std::endl;

class Warrior_V1
{
    public: 
        Warrior_V1(int life,int magic,int attack) : mLife(life),mMagic(magic),mAttack(attack){}
        void burn();
    private:
        int mLife; // 生命值
        int mMagic; // 魔法值
        int mAttack; // 攻击力
};

inline void Warrior_V1::burn()
{
    cout<<"All enemies lose 500 HP..."<<endl;
    cout<<"Warrior lose 300 HP..."<<endl;
    mLife -= 300;
    cout<<"Play special effects..."<<endl;
}

int main()
{
    Warrior_V1 w(1000,0,200);
    w.burn();
    return 0;
}

/*
g++ Warrior_V1.cpp -o Warrior_V1
.\Warrior_V1
*/