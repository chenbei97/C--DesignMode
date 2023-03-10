策略模式和指挥者很像，指挥者可以通过构造函数或者setBuilder()设置不同的构建方法

策略模式基类可以作为Fighter内部的聚合属性，然后通过构造函数或者setStrategy()类似方法设置不同策略
但是Fighter的构造函数不能以Strategy*构造，这就是和建造者模式的区别，只能使用setStrategy()
因为mStrategy是Fighter的聚合属性，所以this就是Fighter*，内部实际上调用了mStrategy->useStrategy(this);

用户可以像这样使用代码，假设战斗者应用这些策略，可以对生命值或者魔法值等属性补给
AddLifeStrategy * s1 = new AddLifeStrategy();
AddMagicStrategy * s2 = new AddMagicStrategy();
Fighter * fighter = new Fighter(s1);
s->useStrategy(); // 增加了生命值
s->setStrategy(s2);
s->useStrategy(); // 增加了魔法值

那么首先定义战斗者类，以及定义子类战士和法师，在Fighter.h中

然后定义策略类Strategy，以及增加魔法值和增加生命值的策略子类，在Strategy.h中
策略类定义了抽象函数useStrategy(Fighter*)，这个函数将会被Fighter的useStrategy()函数内部调用
由于策略需要对Fighter自身生效，所以需要策略类传递Fighter*参数，以便知道对谁操作
操作的函数要求Fighter提供2个成员函数addLife和addMagic
还有一种方法是友元，即Strategy类是Fighter的友元类，Strategy直接可以使用Fighter的私有属性而不是通过成员函数

注意头文件互相包含的问题，Strategy.h不能包含Fighter.h，Fighter.h不能包含Strategy.h但是需要1个前置声明
Fighter.h可以直接给出部分函数的定义（如果不涉及使用Strategy的方法），以下四个函数可以直接定义
void addLife(int life){mlife+=life;};
void addMagic(int magic){mmagic+=magic;};
void print(){printf("life = %d, magic = %d\n",mlife,mmagic);};
void setStrategy(Strategy*strategy){mStrategy = strategy;};
对于void useStrategy()是不允许的，因为useStrategy本身是个纯虚函数，在头文件直接使用导致编译错误，必须放在cpp定义中
// void useStrategy(){mStrategy->useStrategy(this);}; // error
void Fighter::useStrategy(){mStrategy->useStrategy(this);}; // int Fighter.cpp is ok

编译时使用选项联合编译，否则找不到定义
g++ main.cpp Fighter.cpp -o main
.\main

