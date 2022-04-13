#pragma once
#include "agent.h"
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 255
using namespace std;
class superagent:public agent
{
private:
int temp_map[MAX][MAX];
int move_order[MAX][MAX];
int map_size;
int minsteps;
int final_x;
int final_y;
vector<int> final_path;
public:
superagent(int,int,int,int);
void get_size(int);
void readmap(int,int,int);
int bfs();
int findpath();
int getpath(int);
};
