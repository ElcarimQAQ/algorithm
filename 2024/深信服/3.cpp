#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
map<string,int> mp;
int p[N], d[N];

int find(int x) {
    if (p[x] != x){
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

int main() {
    int n, m, a, b, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        d[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        string str;
        int nu;
        cin >> str >> nu;
        mp[str] = nu;
    }
    while(m--){
        cin>>a>>b;
        p[find(a)] = find(b);
    }
    cin>>q;
    int ans = 0;
    while(q--){
        string str1,str2;
        cin>>str1>>str2;
        if(str1 == str2){
            cout<<0<<endl;
            continue;
        }
        if(find(mp[str1]) == find(mp[str2])){
            int root = find(mp[str1]);
            cout<<d[root]-d[mp[str1]]+d[mp[str2]]<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
// 64 位输出请用 printf("%lld")