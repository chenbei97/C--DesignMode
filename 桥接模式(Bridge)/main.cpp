/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 15:04:17
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-18 16:05:03
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

    // ImageOS和ImageFormat之间桥接
    V2::ImageOS * os = new V2::ImageOSMacos;
    V2::ImageFormat * format = new V2::PNGImage(os);
    format->parsefile("");

    return 0;
}
/*
cd 桥接模式(Bridge)
g++ main.cpp -o main
.\main
*/