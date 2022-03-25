#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=30005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int a[105],b[105];
int main()
{
    int t,n,m;
    cin>> t;
    while(t--){
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int i = 1; i <= m; i++)
            cin>>b[i];
        if(n > m)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}