#ifndef FighterMonster_H
#define FighterMonster_H
#include "stdio.h"

namespace V1 {
    class Undead {
        public:
            void isKilled(){
                printf("an undead monster is killed!\n");
            }
    };
    class Element {
        public:
            void isKilled(){
                printf("an element monster is killed!\n");
            }
    };
    class Mechanic {
        public:
            void isKilled(){
                printf("a mechanic monster is killed!\n");
            }
    };

    class Fighter{
        public:
            void kill(Undead* u){u->isKilled();}; // Fighter直接操作底层组件怪物子类
            void kill(Element* u){u->isKilled();}; // 造成紧耦合
            void kill(Mechanic* u){u->isKilled();};
    };
}

namespace V2{
    class Monster{
        public:
            virtual ~Monster(){}
            virtual void isKilled() = 0 ; // 应该提供纯虚函数被Fighter使用,子类去实现此函数,从而可以击杀不同的怪物
    };
    class Undead : public Monster{
        public:
            virtual void isKilled() override
            {
                printf("an undead monster is killed!\n");
            }
    };
    class Element : public Monster{
        public:
            virtual void isKilled() override
            {
                printf("an element monster is killed!\n");
            }
    };
    class Mechanic : public Monster{
        public:
            virtual void isKilled() override
            {
                printf("a mechanic monster is killed!\n");
            }
    };
    class Fighter {
        public:
            void kill(Monster*m){m->isKilled();} 
    };
}
#endif