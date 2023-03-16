#include "FruitBeverage.h"
#include "AddBubble.h"
#include "AddMilk.h"
#include "AddSugar.h"
#include "stdio.h"
int main()
{
    Beverage * fruit = new FruitBeverage();
    BeverageDecorator * milk = new AddMilk(fruit);
    BeverageDecorator * milk_sugar = new AddSugar(milk);
    BeverageDecorator * milk_sugar_bubble = new AddBubble(milk_sugar);

    printf("price = %d\n",milk_sugar_bubble->getprice());
    return 0;
}
/*
g++ main.cpp -o main
.\main
*/