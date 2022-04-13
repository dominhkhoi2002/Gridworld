#include "agent.h"
#include "utilis.h"

agent::agent(int x,int y,int point)
{
    this->x=x;
    this->y=y;
    this->point=point;
}

void agent::action(int action)
{
        if(action==1)
    {
        this->x--;
    }
        else if(action==2)
    {
        this->x++;
    }
        else if(action==3)
    {
        this->y--;
    }
        else if(action==4)
    {
        this->y++;
    }
        else if(action==-1)
    {
        this->x++;
    }
        else if(action==-2)
    {
        this->x--;
    }
        else if(action==-3)
    {
        this->y++;
    }
        else if(action==-4)
    {
        this->y--;
    }
    else if(action==5)
    {
        
    }
}

void agent::minusPoint()
{
    this->point-=5;   
}
void agent::plusPoint()
{
    this->point+=5;   
}
int agent::getX()
{
    return this->x;
}
int agent::getY()
{
    return this->y;
}
int agent::getPoint()
{
    return this->point;
}
void agent::backtostart()
{
    this->x=1;
    this->y=1;
}
void agent::ghostminusPoint()
{
    this->point-=15;   
}