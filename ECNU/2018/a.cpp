#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
ll M[maxn][maxn],K[maxn][maxn];
ll ans[maxn][maxn];


ll cal(ll x,ll y,ll h,ll w){
    ll sum = 0;
    for(ll i = x; i < x + h;i++){
        for(int j = y ;j < y + w; j++){
            sum += M[i][j] * K[i - x +1][j - y +1];
        }
    }
    return sum;

}
int main(){
    ios::sync_with_stdio("false");
    ll n,m,h,w;
    cin>>n>>m;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= m; j++)
            cin>>M[i][j];
    }    
    cin>>h>>w;
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w; j++)
            cin>>K[i][j];
    for(int i = 1;i<= n + h -1; i++){
        ll sum = 0;
        if(i + h -1 > n)
            break;
        for(int j = 1;j <= m + w -1; j++){
            if(j + w -1 > m)
                break;
            sum += cal(i,j,h,w);
            ans[i][j] = sum;
        }
    }
    for(int i = 1;i <= n - h +1;i++){
        for(int j= 1;j <= m - w+1;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
