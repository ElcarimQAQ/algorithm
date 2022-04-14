#include <bits/stdc++.h>
using namespace std;
const int maxn = 35; 
int mi[maxn], ba[maxn];
unordered_map<int ,int> mp;
int l[maxn],r[maxn],vis[maxn];
int n;

int build(int bl,int br, int ml, int mr){
    if(bl > br || ml > mr)
        return 0;
    int root = ba[br];
    int p1 = mp[root];
 
    l[root] = build(bl, bl + p1 - 1 - ml , ml, p1 - 1);
    r[root] = build(br - 1 - (mr - p1 - 1), br - 1, p1 + 1, mr);
    return root;
}

void bfs(int fa) {
    cout<<fa;
    queue<int> q;
    q.push(fa);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if(l[now]){
            cout<<' '<< l[now];
            q.push(l[now]);
        }
        if(r[now]){
            cout<<' '<< r[now];
            q.push(r[now]);
        }
    }
    
}
int main()
{
    std :: ios::sync_with_stdio(false);

    cin>>n;
    for(int i = 1; i <= n ;i++) cin>>ba[i];
    for(int i = 1; i <= n;i++) {
        cin>>mi[i];
        mp[mi[i]] = i;
    }
    build(1,n,1,n);
    bfs(ba[n]);
    return 0;
}