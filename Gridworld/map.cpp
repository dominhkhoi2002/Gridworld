#include "map.h"
#include "utilis.h"
using namespace std;
map::map(int mapsize)
{

    this->mapsize=mapsize;
    for(int i=0;i<mapsize;i++)
    {
        for(int j=0;j<mapsize;j++)
        {   
            if(i==0||i==mapsize-1||j==0||j==mapsize-1)
            {
                this->coord[i][j]=1;
            }
            else this->coord[i][j]=0;
        }
    }
    for(int i=0;i<6;i++)
    {
        this->spawnwall2x2(GetRandom(2,mapsize-2),GetRandom(2,mapsize-2));
        this->spawnwall2x3(GetRandom(2,mapsize-2),GetRandom(2,mapsize-2));

    }
    this->coord[mapsize-2][mapsize-2]=2;
}
void map::spawnwall2x2(int x,int y)
{
    this->coord[x][y]=1;
    this->coord[x+1][y]=1;
    this->coord[x][y+1]=1;
    this->coord[x+1][y+1]=1;
}
void map::spawnwall2x3(int x,int y)
{
    this->coord[x][y]=1;
    this->coord[x+1][y]=1;
    this->coord[x][y+1]=1;
    this->coord[x+1][y+1]=1;
    this->coord[x][y+2]=1;
    this->coord[x+1][y+2]=1;
}
int map::checkwall(int x,int y)
{
    if(this->coord[x][y]==1)
    {
        return 1;
    }
        if(this->coord[x][y]==2)
    {
        return 2;
    }
    else return 0;
}

void map::printmap(int x,int y,int g1x,int g1y,int g2x,int g2y)
{
    for(int i=0;i<this->mapsize;i++)
    {
        for(int j=0;j<this->mapsize;j++)
        {
            if(i==x&&j==y)
            {
                printf("@ ");
            }
            else if(i==g1x&&j==g1y)
            {
                printf("$ ");
            }
            else if(i==g2x&&j==g2y)
            {
                printf("$ ");
            }
            else if(this->coord[i][j]==1)
            {
                printf("# ");
            }
            else if(this->coord[i][j]==2)
            {
                printf("G ");
            }
            else if(this->coord[i][j]==3)
            {
                printf("| ");
            }
            else if(this->coord[i][j]==4)
            {
                printf("- ");
            }
            else printf("  ");
        }
        cout << endl;
    }
}
void map::drawpath(int r,int x,int y)
{
    if(r==2||r==1)
    {
        this->coord[x][y]=3;
    }
    else if(r==4||r==3)
    {
        this->coord[x][y]=4;
    }
}

void map::spawnwall3x3(int x,int y)
{
    this->coord[x][y]=1;
    this->coord[x+1][y]=1;
    this->coord[x][y+1]=1;
    this->coord[x+1][y+1]=1;
    this->coord[x][y+2]=1;
    this->coord[x+1][y+2]=1;
    this->coord[x+2][y]=1;
    this->coord[x+2][y+1]=1;
    this->coord[x+2][y+2]=1;
}
int map::getelm(int x,int y)
{
    return this->coord[x][y];
}
void map::resetmap()
{
    for(int i=0;i<this->mapsize;i++)
    {
        for(int j=0;j<this->mapsize;j++)
        {   
            if(this->coord[i][j]>=3)
            {
                this->coord[i][j]=0;
            }

        }
    }
}
int map::getmapsize()
{
    return this->mapsize;
}