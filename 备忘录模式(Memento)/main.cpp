/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:23:18
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-19 09:09:28
 * @FilePath: \CPPDesignMode\备忘录模式(Memento)\main.cpp
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#include "Memento.h"

int main()
{
    Fighter * fighter = new Fighter(1,"123");
    fighter->display();
    auto m = fighter->createMemento();
    m->display();
    return 0;
}
/*
cd 备忘录模式(Memento)
g++ main.cpp -o main
.\main
*/