#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100005;
vector<int> g[maxn];
int ma[maxn];

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m,k,op,j,u;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>k;
        for(int j = 0;j < k ;j++) { 
            cin>>u;
            g[i].push_back(u);
        }
    }
    int now = 1;
    while(m--) {
        cin>>op>>j;
        if(op == 0){
            now = g[now][j - 1];
        }else if(op == 1){
            ma[j] = now;
            cout<<now<<endl;
        } else {
            now = ma[j];
        }
    }
    cout<<now<<endl;
    return 0;
}