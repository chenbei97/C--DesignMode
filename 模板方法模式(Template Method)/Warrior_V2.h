#include "Fighter_V1.h"

class Warrior_V2 : public Fighter_V1
{
    public:
        Warrior_V2(int life,int magic,int attack):Fighter_V1(life,magic,attack){}
    private:
        virtual bool canUseBurn() override;
        virtual void effect_enemy() override;
        virtual void effect_self() override;
};

inline bool Warrior_V2::canUseBurn()
{
    if (mLife < 300)
        return false;
    return true;
}

inline void Warrior_V2 :: effect_enemy()
{
    cout<<"All enemies lose 500 life..."<<endl;
}

inline void Warrior_V2 :: effect_self()
{
    cout<<"Warrior lose 300 life..."<<endl;
    mLife -= 300;
}