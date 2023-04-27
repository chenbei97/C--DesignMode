#ifndef _STATE_H
#define _STATE_H
#include <iostream>
using std::cout;

namespace V1 {
    class Monster{
        private:
            enum class MonsterState {MS_Rage,MS_Worried,MS_Fear,MS_Dead};
            int mLife;
            Monster::MonsterState mState;
        public:
            Monster(int life):mLife(life),mState(MonsterState::MS_Rage){}
            void attacked(int power) // 被攻击,power为损失的血量
            {
                mLife -= power;
                if (mLife > 400) // 仍然大于400
                {
                    mState = MonsterState::MS_Rage;
                    cout <<"rage state\n";
                }
                else if (mLife > 100)
                {
                    mState = MonsterState::MS_Worried;
                    cout <<"worried state\n";
                }
                else if (mLife > 0)
                {
                    mState = MonsterState::MS_Fear;
                    cout <<"fear state\n";
                }
                else {
                    mState = MonsterState::MS_Dead;
                    cout <<"dead state\n";
                }
            }
    };

    void test()
    {
        Monster m(500);
        m.attacked(50); // 450
        m.attacked(100); // 350
        m.attacked(200); // 150
        m.attacked(80); // 70
        m.attacked(69); // 1
        m.attacked(10); // -9
    }
}

namespace V2 {
    class Monster;

    class MonsterStatus{
        public:
            virtual void attacked(int power,Monster*) = 0; // 依赖倒转,怪物使用状态,所以让怪物成为状态的构造参数
            virtual ~MonsterStatus(){} // 子类重载attacked函数，实现怪物在此状态要做的事情，所以需要传递Monster*
    };

    class MSRage : public MonsterStatus
    {
        public:
            virtual void attacked(int power, Monster* monster)
            {
                cout <<"rage state\n";// 让怪物做些此状态对应的事情
            }
    };

    class MSWorried : public MonsterStatus
    {
        public:
            virtual void attacked(int power, Monster* monster)
            {
                cout <<"worried state\n";// 让怪物做些此状态对应的事情
            }
    };

    class MSFear : public MonsterStatus
    {
        public:
            virtual void attacked(int power, Monster* monster)
            {
                cout <<"fear state\n"; // 让怪物做些此状态对应的事情
            }
    };

    class MSDead : public MonsterStatus
    {
        public:
            virtual void attacked(int power, Monster* monster)
            {
                cout <<"dead state\n";
                // 让怪物做些此状态对应的事情
            }
    };

    class Monster{
        private:
            int mLife;
            MonsterStatus * mStatus;
        public:
            Monster(int life): mLife(life),mStatus(nullptr){
                mStatus = new MSRage();
            }
            ~Monster(){if(mStatus!=nullptr) delete mStatus;}
            void attacked(int power)
            {
                mLife -= power;

                if (mLife > 400)
                {
                    delete mStatus;
                    mStatus = new MSRage();
                    mStatus->attacked(power,this); // 把在这里写的所有代码例实质上转移到了MSRage
                }
                else if (mLife > 100)
                {
                    delete mStatus;
                    mStatus = new MSWorried(); // 同理
                    mStatus->attacked(power,this);
                }
                else if (mLife > 0)
                {
                    delete mStatus;
                    mStatus = new MSFear();
                    mStatus->attacked(power,this); // 同理
                }
                else {
                    delete mStatus;
                    mStatus = new MSDead();
                    mStatus->attacked(power,this); // 同理
                }
            }
    };

    void test(){
        Monster m(500);
        m.attacked(50); // 450
        m.attacked(100); // 350
        m.attacked(200); // 150
        m.attacked(80); // 70
        m.attacked(69); // 1
        m.attacked(10); // -9
    }
}
#endif