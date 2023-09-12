#include <bits/stdc++.h>
using namespace std;
const int N=11;

vector<string> M;
int vis[50][50];
//上下左右走位
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
// 记录路径
stack<pair<int, int>> path;
bool flag = false;
pair<int, int> pre[N][N];

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


struct node{
    int x,y,l;
};

node s,e;
void bfs(int x,int y)
{
    memset(vis,-1,sizeof(vis));
    queue<node> q;
    q.push(s);
    vis[s.x][s.y] = 0;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        for(int i = 0; i < 4;i++){
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;  // 出界
            if (M[nx][ny] == 'F') continue;  // 障碍物
            if (vis[nx][ny] != -1) continue;  // 之前已经遍历过
            node next = {nx,ny,now.l+1};
            vis[nx][ny] = vis[now.x][now.y]+1;
            pre[nx][ny] = {now.x, now.y};
            if (M[nx][ny] == 'E')
                e = next; 
            q.push(next);
        }
    }
}

// 打印最短路径
void printP(int x, int y){
    if(x == 0 && y == 0) {
        while (path.size() != 0)
        {
            cout<<path.top().first<<' '<< path.top().second<<endl;
            path.pop();
        }
        
        return;
    }
    path.push(pre[x][y]);
    printP(pre[x][y].first , pre[x][y].second);
}

int main()
{
    s = {0, 0 , 0};
    M = generateM();
    M[10][10] = 'E';
    bfs(0, 0);
    cout <<"shortest path lenth is: " << vis[e.x][e.y] + 1 << endl;
    path.push({10, 10});
    printP(10 , 10);
}
