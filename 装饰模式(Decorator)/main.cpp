#include "ScrollDecorator.h"
#include "BorderDecorator.h"
#include "ListCtrl.h"

int main()
{
    Control * listctrl = new ListCtrl();
    // listctrl->draw(); // 可以注释掉,装饰的时候内部会调用

    ControlDecorator * dec1 = new BorderDecorator(listctrl);
    // dec1->draw(); // 带边框

    ControlDecorator * dec2 = new ScrollDecorator(dec1);
    dec2->draw(); // 带边框也带滚动条
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/