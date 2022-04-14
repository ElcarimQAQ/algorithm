#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005; 
unordered_map<int, pair<int, int>> g;
int pre[maxn];

int find(int x){
    if(pre[x] != x) pre[x] = find(pre[x]);
    return pre[x];
}

int join(int x,int y)
{
    if(find(x) != find(y)) {
        pre[find(x)] = find(y);
        return 0;
    }
    return 1;
}

int main()
{
    int n,m,k,a,b,x;
    scanf("%d%d%d", &n,&m,&k);
    for(int i = 1;i<= m;i++){
        scanf("%d%d", &a,&b);
        g[i] = {a,b};
    }
    while(k--){
        int cnt = n - 1;
        for(int i =1; i <= n; i++)
            pre[i] = i;
        scanf("%d", &x);
        for(int i =1 ;i<= m;i++) {
            if(g[i].first == x || g[i].second == x) continue;
            if(!join(g[i].first, g[i].second)) cnt--;
        }
        // cout<<cnt - 1 <<endl;
        printf("%d\n",cnt - 1);
    }
    return 0;
}