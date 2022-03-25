#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
typedef long long ll;
ll g[maxn][maxn];
ll qz[maxn][maxn];


int main()
{
    int n,m;
    ll k;
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>g[i][j]; 
            qz[i][j] = qz[i][j - 1] + g[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){

        }
    }


}