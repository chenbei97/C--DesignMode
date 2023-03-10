#ifndef _Strategy_H
#define _Strategy_H

class Strategy
{   
    public:
        virtual ~Strategy(){}
        virtual void useStrategy(Fighter*) = 0;
};

class AddLifeStrategy: public Strategy
{
    public:
        virtual void useStrategy(Fighter* fighter) override
        {
            fighter->addLife(200);
        }
};

class AddMagicStrategy: public Strategy
{
    public:
        virtual void useStrategy(Fighter* fighter) override
        {
            fighter->addMagic(200);
        }
};

#endif