#include "Warrior_V2.h"
#include "Mage_V2.h"

int main()
{
    Fighter_V1 * warrior = new Warrior_V2(1000,0,200);
    Fighter_V1 * mage = new Mage_V2(800,200,300);

    for(int i = 0; i<4;++i)
    {   
        cout<<"use burn "<<i+1<<" count\n";
        warrior->burn();
        mage->burn();
    }

    return 0;
}

/*
g++ main.cpp -o main
.\main
*/