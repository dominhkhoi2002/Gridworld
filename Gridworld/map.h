#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#define MAX 255

class map
{
    private:
        int coord[MAX][MAX];
        int mapsize;
    public:
        map(int);
        int getelm(int,int);
        void spawnwall2x2(int,int);
        void spawnwall2x3(int,int);
        void drawpath(int,int,int);
        void printmap(int,int,int,int,int,int);
        ~map();
        int checkwall(int,int);
        void spawnwall3x3(int,int);
        void resetmap();
        int getmapsize();
};