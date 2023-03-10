#include "Fighter.h"
#include "Strategy.h"

// void Fighter::addLife(int life){mlife+=life;};
// void Fighter::addMagic(int magic){mmagic+=magic;};
// void Fighter::print(){printf("life = %d, magic = %d\n",mlife,mmagic);};
// void Fighter::setStrategy(Strategy*strategy){mStrategy = strategy;};
void Fighter::useStrategy(){mStrategy->useStrategy(this);};
