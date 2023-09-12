#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N=11;

vector<string> M;
int vis[50][50];
//上下左右走位
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
// 记录路径
vector<pair<int, int>> path;
bool flag = false;

// 障碍坐标
vector<pair<int, int>> obstacles = {
    {3, 2}, {6, 6}, {7, 0}, {2, 8}, {5, 9}, {8, 4},
    {2, 4}, {0, 8}, {1, 3}, {6, 3}, {9, 3}, {1, 9},
    {3, 0}, {3, 7}, {4, 2}, {7, 8}, {2, 2}, {4, 5},
    {5, 6}, {10, 5}, {6, 2}, {6, 10}, {4, 0}, {7, 5},
    {7, 9}, {8, 1}, {5, 7}, {4, 4}, {8, 7}, {9, 2},
    {10, 9}, {2, 6}
};

// 生成迷宫字符串矩阵
vector<string> generateM() {
    vector<string> M(N, string(N, 'T'));  // 初始化迷宫矩阵为全部为'T'
    
    for (const auto& obstacle : obstacles) {
        int x = obstacle.first;
        int y = obstacle.second;
        M[x][y] = 'F';  // 设置障碍位置为'F'
    }
    
    return M;
}


void dfs(int x,int y)
{
    path.push_back({x,y});
    vis[x][y] = 1;
	if(M[x][y] == 'E')//走到终点
	{
        flag = true;
		return;
	}
	for(int i = 0;i < 4;i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx >= 0 && tx < N && ty >= 0 &&ty < N && vis[tx][ty] == 0 && M[tx][ty] != 'F')//下一步未出界且下一步位置未被访问过(vis[][])  
		{
			dfs(tx,ty);
            if (flag) 
                return;
            path.pop_back();
			vis[tx][ty] = 0;//回溯
		}
    }
}

int main()
{
    M = generateM();
    M[10][10] = 'E';
    dfs(0, 0);
    cout <<"path lenth is: " << path.size() << endl;
    for(auto i : path)
        cout<<i.first<<' '<< i.second<<endl;
    
}
