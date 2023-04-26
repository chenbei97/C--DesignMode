#ifndef _COMMAND_H
#define _COMMAND_H
#include <stdio.h>
#include <list>

namespace V1{ // 厨师直接做菜,问题在于菜多了,厨师容易记错,所以需要便签(命令)
    class COOK
    {
        private:
            char mVersion[2] = {'V','1'};
        public:
            void cook_fish(){printf("%c%c => cooker is cooking fish!\n",mVersion[0],mVersion[1]);};
            void cook_meat(){printf("%c%c => cooker is cooking meat!\n",mVersion[0],mVersion[1]);};
        public:
            void setVersion(char v){mVersion[1] = v;}
    };
    void test()
    {
        COOK * cook = new COOK();
        cook->cook_fish();
        cook->cook_meat();
    }
}

namespace V2 { //为了解决V1的问题,把做菜的函数动作可以封装成对象,含义就是便签
    // 由于有多个不同的做菜动作(命令),所以需要一个抽象命令类 
    class Command{
        protected:// 子类需要在execute函数内使用该对象
            V1::COOK * mCooker;
        public:
            Command(V1::COOK * cook):mCooker(cook){}
            virtual ~Command(){}
            virtual void execute() = 0; //命令的执行动作
    };

    class CommandCookFish : public Command{
        public:
            CommandCookFish(V1::COOK*cook):Command(cook){}
            virtual void execute() override // 其实就是用此函数对厨师的做菜动作进行了1层封装
            {
                mCooker->cook_fish();
            }
    };
    class CommandCookMeat : public Command{
        public:
            CommandCookMeat(V1::COOK*cook):Command(cook){}
            virtual void execute() override 
            {
                mCooker->cook_meat();
            }
    };

    void test()
    {
        V1::COOK cook;
        cook.setVersion('2');

        Command * c1 = new CommandCookFish(&cook); // 创造命令动作
        Command * c2 = new CommandCookMeat(&cook);

        c1->execute(); // 让命令对象执行代替厨师直接执行,实现1层抽象解耦
        c2->execute();
    } 
}

namespace V3 { // 真正的问题没解决,10个菜需要创建10个命令对象
    // 其实可以借助中间对象服务员类,内部使用列表存储所有命令,服务员交给厨师即可
    class Waiter{
        private:
            std::list<V2::Command*> mCommandList;
        public:
            void addCommand(V2::Command* command)
            {
                mCommandList.push_back(command);
            }
            void removeCommand(V2::Command* command)
            {
                mCommandList.remove(command);
            }
            void notify() // 一次性通知厨师做完所有菜
            {
                for(auto iter = mCommandList.begin(); iter != mCommandList.end();++iter)
                    (*iter)->execute();
            }
    };
    void test()
    {
        V1::COOK cook;
        cook.setVersion('3');

        V2::Command * c1 = new V2::CommandCookFish(&cook);
        V2::Command * c2 = new V2::CommandCookMeat(&cook);
        Waiter * waiter = new Waiter();
        waiter->addCommand(c1);
        waiter->addCommand(c2);
        waiter->notify();
    }
}

#endif