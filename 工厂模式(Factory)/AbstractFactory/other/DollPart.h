#ifndef DollPart_H
#define DollPart_H

#include "stdio.h"

class DollPart
{
    public:
        virtual void describe() = 0;
        virtual ~DollPart(){}
};

class Body : public DollPart
{

};

class Shoes : public DollPart
{

};

class Clothes : public DollPart
{

};
#endif