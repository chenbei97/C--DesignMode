/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:24:52
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-19 10:04:48
 * @FilePath: \CPPDesignMode\职责链模式(DutyChain)\DutyChain.h
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */

#ifndef DutyChain_H
#define DutyChain_H
#include <string>
#include <iostream>
using std::cout;
using std::string;

class A
{
private:
    int msalary;
public:
    A(int salary):msalary(salary){};
    void addSalary(int s) {
        msalary += s;
        if (msalary <= 1000) { // 如果新增判断就要增加if分支
            
        } else if ( msalary <= 5000) {
            
        } else {
            // ...
        }
        cout<<"add "<<s<<std::endl;
    };
};

class DutyChain
{
public:
    void setNext(DutyChain* d){next = d;}
    virtual void processEvent(int salary) = 0;
    virtual ~DutyChain(){}
protected:
    void sendEvent(int salary){
        if (next != nullptr) {
            next->processEvent(salary); // 不同子类实现不同处理方式
        } else {
            cout<<"can not process!\n";
        }
    }
private:
    DutyChain * next = nullptr;
};

class Manager1: public DutyChain
{
public:
    void processEvent(int salary) {
        if (salary <= 1000) {
            cout<<"manager1 add "<<salary<<std::endl;
        } else {
            cout<<"manager1 can not process "<<std::endl;
            sendEvent(salary);
        }
    }
};

class Manager2: public DutyChain
{
public:
    void processEvent(int salary) {
        if (salary <= 5000) {
            cout<<"manager2 add "<<salary<<std::endl;
        } else { 
            cout<<"manager2 can not process "<<std::endl;
            sendEvent(salary);
        }
    }
};
#endif