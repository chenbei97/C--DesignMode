/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 15:04:17
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-18 15:43:58
 * @FilePath: \CPPDesignMode\桥接模式(Bridge)\main.cpp
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */
#include "Bridge.h"

int main()
{
    V1::JPGImageWindow jpgwin;
    jpgwin.draw("");
    V1::PNGImageLinux pnglinux;
    pnglinux.draw("");
    return 0;
}
/*
cd C:\Users\Lenovo\Desktop\CPPDesignMode\桥接模式(Bridge)
g++ main.cpp -o main
.\main
*/