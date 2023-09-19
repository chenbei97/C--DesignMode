/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:19:34
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-19 08:22:57
 * @FilePath: \CPPDesignMode\中介者模式(Mediator)\main.cpp
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#include "Mediator.h"

int main()
{
    LoginMediator window;
    window.createWidgets();
    window.login();
    return 0;
}
/*
cd 中介者模式(Mediator)
g++ main.cpp -o main
.\main
*/