#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=505;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
 
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
     ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        string g[maxn];
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            cin>>g[i];
        }
        for(int i = (n%3) == 0; i < n; i += 3 ){
            for(int j = 0; j < m; j++)
                g[i][j] = 'X';
            int pos = 0;
            if((g[i + 1][1] == 'X' || g[i + 2][1] == 'X' )){
                pos = 1;
            }
            g[i + 1][pos] = 'X';
            g[i + 2][pos] = 'X';
        }
        for(int i = 0; i < n; i++)
            cout<<g[i]<<endl;
    }
    return 0;
}