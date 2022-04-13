#include "superagent.h"
using std::cout;
using std::cin;

superagent::superagent(int x,int y,int point,int mapsize):agent(x,y,point)
{
    this->map_size=mapsize;
}
void superagent::readmap(int x, int y,int elm)
{
    this->temp_map[x][y]=elm;
}


int superagent::bfs()
{
class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

    QItem source(this->x, this->y, 0);
    bool visited[this->map_size][this->map_size];
    for (int i = 0; i < this->map_size; i++) {
        for (int j = 0; j < this->map_size; j++)
        {
            if (this->temp_map[i][j] == 1)
                visited[i][j] = true;
            else
                visited[i][j] = false;

        }
    }

    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        QItem p = q.front();
        q.pop();

        // Destination found;
        if (this->temp_map[p.row][p.col] == 2)
        {
            this->final_x = p.row;
            this->final_y = p.col;
            return p.dist;
        }
        // moving up
        if (p.row - 1 >= 1 &&
            visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            this->move_order[p.row - 1][p.col] = 1;
            visited[p.row - 1][p.col] = true;
        }
        // moving down
        if (p.row + 1 < this->map_size-1 &&
            visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            this->move_order[p.row + 1][p.col] = 2;
            visited[p.row + 1][p.col] = true;
        }
        // moving left
        if (p.col - 1 >= 1 &&
            visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            this->move_order[p.row][p.col - 1] = 3;
            visited[p.row][p.col - 1] = true;
        }
         // moving right
        if (p.col + 1 < this->map_size-1 &&
            visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            this->move_order[p.row][p.col + 1] = 4;
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}
int superagent::findpath()
{
    int countsteps=this->bfs();
    if(countsteps==-1)
    {
        return 0;
    }
    else
    {
        int i=this->final_x;
        int j=this->final_y;
        while(this->move_order[i][j]!=0)
        {
            this->final_path.push_back(this->move_order[i][j]);
            if(this->move_order[i][j]==1)
            {
                i++;
            }
            else if(this->move_order[i][j]==2)
            {
                i--;
            }
            else if(this->move_order[i][j]==3)
            {
                j++;
            }
            else if(this->move_order[i][j]==4)
            {
                j--;
            }
        }
        std::reverse(final_path.begin(), final_path.end());
    }
    return countsteps;
}


int superagent::getpath(int i)
{
    return this->final_path[i];
}
    

