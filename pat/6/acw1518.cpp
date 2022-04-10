#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
unordered_map<string, vector<pair<string, int>>> g;
unordered_map<string, int> vis,w;
int n, k, t;
struct bp{
    string name;
    int num;
};
bool cmp(bp a, bp b){
    return a.name <  b.name;
}

vector<bp> ans;
string tou ; 
int total,cnt;

void dfs(string u) {
    vis[u] = 1;
    cnt++;
    for(auto v : g[u]) {
        total += v.second; //bug3,所有能连的都加进来，才是实际长度2倍，不需要避免走过的点
        if(vis[v.first]) //没被访问过
            continue;
        if(w[v.first] > w[tou])
            tou = v.first;
        dfs(v.first);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    string n1, n2;
    while (n--) {
        cin >> n1 >> n2 >> t;
        g[n1].push_back({ n2, t });
        g[n2].push_back({ n1, t });
        w[n1] += t;
        w[n2] += t;
        vis[n1] = vis[n2] = 0;
    }
    for(auto u : vis){
        if(u.second == 0) {
            tou = u.first; //bug1,头的值初始化要在dfs外面
            cnt = 0,total= 0;
            dfs(tou);
            if(cnt >= 3 && total > 2 * k)
                ans.push_back({tou,cnt}); //bug2,判断连通块是否符合条件在走完之后
        }
    }
    if(ans.empty())
        cout<<0<<endl;
    else{
        cout<<ans.size()<<endl;
        sort(ans.begin(), ans.end(), cmp);
        for(auto u : ans) {
            cout<< u.name <<' '<<u.num<<endl;
        }
    }
    return 0;
}