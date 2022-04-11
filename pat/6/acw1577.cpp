#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
int w[maxn], g[maxn][maxn];
int st[maxn], dis[maxn], cnt[maxn], sum[maxn], node[maxn];
//标记，       最小成本，  路线数量，   幸福感，   最小点数
unordered_map<string, int> mp;
string city[maxn];
int n,k,c;
int pre[maxn];
stack<string> road;

void dij()
{
    memset(dis, INF, sizeof dis);
    memset(node, INF, sizeof node);
    dis[0] = 0, cnt[0] = 1, sum[0] = 0, node[0] = 0; //bug4，不认真看题，初始点不算结果找了一万年bug
    for(int i = 0;i < n; i++) {
        int t = -1;
        for(int j = 0;j < n; j++)
            if(!st[j] && ( t == -1 || dis[j] < dis[t]) )  // bug3,括号位置错了
                t = j;
        
        st[t] = 1; //bug2,加入t后要标记
        for(int j = 0;j < n; j++) {
            if(dis[j] > dis[t] + g[t][j]) {
                pre[j] = t;
                dis[j] = dis[t] + g[t][j];
                cnt[j] = cnt[t] ;
                sum[j] = sum[t] + w[j];
                node[j] = node[t] + 1;
            } else if( dis[j] == dis[t] + g[t][j]) { 
                cnt[j] += cnt[t] ;

                if(sum[t] + w[j] == sum[j]){ //幸福感相同
                    if(node[t] + 1 < node[j]){ //t节点少，否则无需更新
                        pre[j] = t;
                        node[j] = node[t] + 1;
                    } 
                } else {
                    if(sum[t] + w[j] > sum[j]) {
                        pre[j] = t;
                        sum[j] = sum[t] + w[j];
                        node[j] = node[t] + 1;
                    }
                }
            }
        }
    }
}

void printRoad(int t)
{
    road.push(city[t]);  //bug5,末尾点忘记放进去了
    while (pre[t] != 0 )
    {
        t = pre[t];
        road.push(city[t]); 
    }
    cout<<city[0];
    while(!road.empty()){
        cout<<"->"<<road.top();
        road.pop();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    string c1,c2;
    cin>> n >> k >> city[0];
    mp[city[0]] = 0;
    w[0] = 0;
    for(int i = 1; i <= n - 1; i++) { //bug1, 节点序号[0,n-1]
        cin>>city[i]>>c;
        mp[city[i]] = i;
        w[i] = c;
    }
    memset(g ,INF , sizeof g);
    while(k--) {
        cin>>c1>>c2>>c;
        int u = mp[c1], v = mp[c2];
        g[u][v] = g[v][u] = min(g[u][v], c);
    }
    dij();
    int t = mp["ROM"];
    cout<< cnt[t] <<' '<< dis[t] <<' '<< sum[t] <<' ' << sum[t]/node[t]<<endl; 
    printRoad(t);
    return 0;
}