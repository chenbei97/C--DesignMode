#include "Fighter_V1.h"

class Mage_V2 : public Fighter_V1
{
    public:
        Mage_V2(int life,int magic,int attack):Fighter_V1(life,magic,attack){}
    private:
        virtual bool canUseBurn() override;
        virtual void effect_enemy() override;
        virtual void effect_self() override;
};

inline bool Mage_V2::canUseBurn()
{
    if (mMagic < 100)
        return false;
    return true;
}

inline void Mage_V2 :: effect_enemy()
{
    cout<<"All enemies lose 650 life..."<<endl;
}

inline void Mage_V2 :: effect_self()
{
    cout<<"Mage lose 100 magic..."<<endl;
    mMagic -= 100;
}