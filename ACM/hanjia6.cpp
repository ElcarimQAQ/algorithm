#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e5+7;
const int mod=998244353;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int dir[41][2] ={1,0,-1,0,0,1,0,-1};
int vis[105][105];
int xs,ys,xe,ye;
int n,m;
string g[105];

struct node{
    int x,y;
    int l;
};

int bfs()
{
    queue<node> q;
    node st;
    st.x = xs-1;
    st.y = ys-1;
    st.l = 0;
    q.push(st);
    while(!q.empty()){
        node now =q.front();
        q.pop();
        if(now.x == xe-1 && now.y == ye-1)
            return now.l;
        int nx,ny,nl;
        for(int i =0; i < 4;i++){
            nx = now.x + dir[i][0];
            ny = now.y + dir[i][1]; 
            nl = now.l +1;
            if(0 <= nx && nx < m && 0<= ny &&ny<n && vis[nx][ny] == 0 && g[nx][ny] == '.'){
                node ne;
                ne.x = nx;
                ne.y = ny;
                ne.l = nl;
                q.push(ne);
                vis[nx][ny] = 1;
            }
        }
    }
     return -1;
}
int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    cin>>xs>>ys>>xe>>ye;
    for(int i=0;i<n;i++)
        cin>>g[i];
    int ans = bfs();
    if(ans == -1)
        cout<<-1<<endl;
    else
        cout<<ans*100<<endl;
    return 0;
}
