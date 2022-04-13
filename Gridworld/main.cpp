#include "map.h"
#include "agent.h"
#include "superagent.h"
#include "utilis.h"
using namespace std;

int inputMove(char c)
{
    if(c=='w') return 1;
    else if(c=='s') return 2;
    else if(c=='a') return 3;
    else if(c=='d') return 4;
    else return 5;

}
int botaction(int r)
{
    if(r%2==0)
    {
        return 2;
    }
    else if(r%2==1)
    {
        return 4;
    }
    else return 5;
}

int main()
{
    srand((unsigned int)time(NULL));
    int mapsize=20;
    int step=100;
    map *bando= new map(mapsize);
    agent *player=new agent(1,1,100);
    agent *ghost=new agent(mapsize-2,1,100);
    agent *ghost2=new agent(1,mapsize-2,100);
    int g1;
    int g2;
    char c;
    int finish=0;
    cout << "\033[2J\033[1;1H";
    cout << "Bam WASD de di chuyen: "<< endl;
    bando->printmap(player->getX(),player->getY(),ghost->getX(),ghost->getY(),ghost2->getX(),ghost2->getY());
    for(int i=0;i<step;i++)
    {
        c=getch();
        if(inputMove(c)==5)
        {
            cout << "\033[2J\033[1;1H";
            cout << "WASD only!" << endl;;
        }
        else{
            g1=GetRandom(1,4);
            g2=GetRandom(1,4);
            player->action(inputMove(c));
            ghost->action(g1);
            ghost2->action(g2);
            if(bando->checkwall(ghost->getX(),ghost->getY())==1||bando->checkwall(ghost->getX(),ghost->getY())==2||(ghost->getX()==ghost2->getX()&&ghost->getY()==ghost2->getY())||(ghost->getX()==1&&ghost->getY()==1))
            {
                ghost->action(-g1);
            }
            if(bando->checkwall(ghost2->getX(),ghost2->getY())==1||bando->checkwall(ghost2->getX(),ghost2->getY())==2||(ghost2->getX()==1&&ghost2->getY()==1))
            {
                ghost2->action(-g2);
            }
            cout << "\033[2J\033[1;1H";
        if(bando->checkwall(player->getX(),player->getY())==1)
        {
            cout << "Hit a wall! -5 points." << endl;
            player->minusPoint();
            player->action(-inputMove(c));
        }
        else if(bando->checkwall(player->getX(),player->getY())==2)
        {
            cout << "Goal reached!" << endl;
            player->plusPoint();
            finish=1;
            break;
        }
        else if((player->getX()==ghost->getX()&&player->getY()==ghost->getY())||(player->getX()==ghost2->getX()&&player->getY()==ghost2->getY()))
        {
            cout << "Hit a ghost! -15 points and go back to start!" << endl;
            player->ghostminusPoint();
            player->backtostart();
        }

        else cout <<"You moved. " << endl;
        }
        bando->printmap(player->getX(),player->getY(),ghost->getX(),ghost->getY(),ghost2->getX(),ghost2->getY());
        
    }
    if(finish==0)
    {
        cout << "Out of moves" <<endl;
    }
    
    cout << "Total points: " << player->getPoint() << endl << endl;
    bando->resetmap();

    cout << "Bot turns?[y/n] : " << endl;  
    char botturn;
    botturn=getch();
    if(botturn=='y')
    {
        cout << "\033[2J\033[1;1H";
        int r=0;
        int wallhit=0;
        superagent *superplayer=new superagent(1,1,100,bando->getmapsize());
        for(int i=0;i<mapsize;i++)
        {
            for(int j=0;j<mapsize;j++)
            {
                superplayer->readmap(i,j,bando->getelm(i,j));
            }
        }
        int minsteps=superplayer->findpath();
        if(minsteps==-1)
        {
            cout << "No path found!" << endl;
        }
        else
        {
            for(int i=0;i<step;i++)
                {
                    superplayer->action(superplayer->getpath(i));
                    if(bando->checkwall(superplayer->getX(),superplayer->getY())==2)
                        {
                            superplayer->plusPoint();
                            cout << "Super Bot reach the goal!" << endl;
                            break;
                        }
                    else
                        {
                            bando->drawpath(superplayer->getpath(i),superplayer->getX(),superplayer->getY());
                        }
                }    
            bando->printmap(1,1,mapsize+1,mapsize+1,mapsize+1,mapsize+1);
            cout << "Minimum steps: " << minsteps << endl;
        }

    }
    else cout << "Super Bot doesn't play!" << endl;
}
    