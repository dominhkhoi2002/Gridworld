#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
class agent
{
    protected:
        int x;
        int y;
        int point;
    public:
        agent(int,int,int);
        ~agent();
        void action(int);
        void backtostart();
        int getPoint();
        void minusPoint();
        void ghostminusPoint();
        void plusPoint();
        int getX();
        int getY();

};