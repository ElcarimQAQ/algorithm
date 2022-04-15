#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int b[maxn],pre[maxn];
set<int> bird;

int find(int x) {
    if(pre[x] != x) pre[x] = find(pre[x]);
    return pre[x];
}

int join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) {
        pre[pa] = pb;
        return 0;
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,k,q,u,v,cnt = 0;
    for(int i = 0; i < maxn; i++)
        pre[i] = i;
    cin>>n;
    for(int i = 0;i < n;i++) {
        cin>>k;
        cin>>b[0];
        bird.insert(b[0]);
        for(int i = 1;i < k; i++) {
            cin>>b[i];
            bird.insert(b[i]);
            if(join(b[0], b[i]) == 0) cnt++;
        }
    }
    cout<<bird.size() - cnt <<" " << bird.size()<<endl;
    cin>>q;
    while(q--) {
        cin>>u>>v;
        if(find(u) != find(v)) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}