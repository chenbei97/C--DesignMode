/*** 
 * @Author: chenbei97 chenbei_electric@163.com
 * @Date: 2023-09-18 16:28:58
 * @LastEditors: chenbei97 chenbei_electric@163.com
 * @LastEditTime: 2023-09-19 11:13:13
 * @FilePath: \CPPDesignMode\访问者模式(Visitor)\main.cpp
 * @Copyright (c) 2023 by ${chenbei}, All Rights Reserved. 
 */

#include "Visitor.h"

int main()
{
    Visitor * buy = new BuyVisitor();
    Visitor * sell = new SellVisitor();
    buy->visit_apple(new Apple);
    buy->visit_banana(new Banana);
    sell->visit_apple(new Apple);
    sell->visit_banana(new Banana);

    cout<<"buy price = "<<static_cast<BuyVisitor*>(buy)->getTotal()
    << " sell price = "<<static_cast<SellVisitor*>(sell)->getTotal()
    << std::endl;;

    auto v1 = new BuyVisitor;
    auto apple = new Apple;
    apple->accept(v1);
    cout<<"buy apple price = "<<v1->getTotal()<<std::endl;

    return 0;
}
/*
cd 访问者模式(Visitor)
g++ main.cpp -o main
.\main
*/