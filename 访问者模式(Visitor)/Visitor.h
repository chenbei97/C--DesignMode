/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:28:58
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-10-20 17:30:48
 * @FilePath: \CPPDesignMode\访问者模式(Visitor)\Visitor.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#ifndef Visitor_H
#define Visitor_H

#include <string>
#include <iostream>
#include <list>
using std::cout;
using std::string;
using std::list;

class Visitor;
class Fruit {
public:
    virtual ~Fruit(){}
    virtual void accept(Visitor * e) = 0;
    virtual float price() = 0;
};

class Apple : public Fruit {
public:
    virtual float price()override{return 10.8f;};
    virtual void accept(Visitor * e) override;
};

class Banana : public Fruit {
public:
    virtual float price()override{return 25.3f;};
    virtual void accept(Visitor * e) override;
};

class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visit_apple(Apple*) = 0;
    virtual void visit_banana(Banana*) = 0;
};

class BuyVisitor : public Visitor{
private:
    float total = 0.0f;
public:
    float getTotal() {return total;}
    virtual void visit_apple(Apple*a) override{
        cout <<"buy apple\n";
        total += a->price();
    };
    virtual void visit_banana(Banana*b) override{
        cout <<"buy banana\n";
        total += b->price();
    };
};

class SellVisitor : public Visitor{
private:
    float total = 0.0f;
public:
    float getTotal() {return total;}
    virtual void visit_apple(Apple*a) override{
        cout <<"sell apple\n";
        total += a->price() + 2.5f;
    };
    virtual void visit_banana(Banana*b) override{
        cout <<"sell banana\n";
        total += b->price()+3.2f;
    };
};

inline void Apple::accept(Visitor * e) {
    e->visit_apple(this);
};

inline void Banana::accept(Visitor * e) {
    e->visit_banana(this); 
};
#endif

/*
    使用者类以参观者类为构造函数 A(B*),有个setB(B*)方法
    访问者类定义访问不同使用者子类的方法 B: visit_A1(A1*);visit_A2(A2*)
    A的子类A1->setB(B*b)=>b->visit_A1()
*/