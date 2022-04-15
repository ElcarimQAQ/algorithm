#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
vector<pair<int,int> >edge;
int c[maxn];
set<int> cnt;

int main() {
    std::ios::sync_with_stdio(false);
    int n,m,a,b,k;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edge.push_back({a,b});
    }
    cin>>k;
    while(k--) {
        cnt.clear();
        bool flag = true;
        for(int i =0; i < n; i++) {
            cin>>c[i];
            cnt.insert(c[i]);
        }
        for(auto v : edge) {
            if(c[v.first] == c[v.second]){
                puts("No");
                flag = false;
                break;
            }
        }
        if(flag) printf("%d-coloring\n",cnt.size()); 
    }
    
    return 0;
}