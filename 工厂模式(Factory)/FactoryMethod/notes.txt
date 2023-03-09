工厂方法模式就是为了解决简单工厂模式中if/switch逻辑分支较长的问题
常说的工厂模式也是指工厂方法模式，为了解决分支多的问题，就需要引入新的工厂类

每种怪物都配套一个工厂类，这些工厂类共同继承1个工厂父类，见MonsterFactory.h
和MonsterFactorySub.h
然后还可以定义一个全局函数方便使用
inline Monster * global_CreateMonster(MonsterFactory*factory)
{
    return factory->createMonster();
}

可以看到MonsterFactory和Monster类，以及全局函数属于稳定部分，不需要修改
如果增加新的怪物，配套好新的怪物工厂即可，不需要对原有的代码进行修改
这样实现了开放-封闭原则，有了新的怪物只需要增加新类拓展即可，怪物类之间也没有影响

工厂方法模式可以隐藏所有的怪物类不暴露给开发者，但是如果不怕暴露怪物名，且不想写这么多工厂子类
还可以采用模板泛型的方法，在ChildFactory.h定义，ChildFactory的T可以是任何怪物类，即可创建任何怪物类
这样一个模板工厂类节省了许多新类，这种写法也是ok的,那么主程序的使用方法就是这样的：
ChildFactory<UndeadMonster> fac;
auto m = fac.createMonster();