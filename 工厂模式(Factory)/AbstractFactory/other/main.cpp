#include "BarbieDoll.h"
#include "ChinaFactory.h"
#include "UsaFactory.h"
#include "JapanFactory.h"

int main()
{
    // 制作2个芭比娃娃
    // 1. 全部使用中国厂商制造
    // 2. 身体中国厂商,衣服日本,鞋子美国
    auto chinaF = new ChinaFactory;
    auto usaF = new UsaFactory;
    auto japanF = new JapanFactory;

    // 1.
    auto body1 = chinaF->createBody();
    auto cloth1 = chinaF->createClothes();
    auto shoe1 = chinaF->createShoes();
    auto doll1 = BarbieDoll(body1,cloth1,shoe1);
    doll1.assemble();

    // 2.
    auto body2 = chinaF->createBody();
    auto cloth2 = usaF->createClothes();
    auto shoe2 = japanF->createShoes();
    auto doll2 = BarbieDoll(body2,cloth2,shoe2);
    doll2.assemble();
    return 0;
}

/*
g++ main.cpp -o main
.\main
*/