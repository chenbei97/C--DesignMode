/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:23:18
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-19 09:59:56
 * @FilePath: \CPPDesignMode\职责链模式(DutyChain)\main.cpp
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#include "DutyChain.h"

int main()
{
    A a(17000);
    a.addSalary(1001);

    Manager1 * m1 = new Manager1;
    Manager2 * m2 = new Manager2;
    m1->setNext(m2);
    m2->setNext(nullptr);
    m1->processEvent(5001);
    return 0;
}
/*
cd 职责链模式(DutyChain)
g++ main.cpp -o main
.\main
*/