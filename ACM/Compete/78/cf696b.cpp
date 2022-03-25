#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int vis[maxn];
 
void prime()
{
    int p=0;
    for(int i=2 ; i<maxn; i++){
        vis[i]=1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                vis[i]=0;
                break;
            }
        }
    }
}
 
int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    prime();	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,d;
    cin>>t;
    while(t--){
        cin>>d;
        int a,b;
        for(int i=1+d; ;i++){
            if(vis[i]==1){
                a=i;
                break;
            }
        }
        for(int i=a+d;;i++){
            if(vis[i]==1){
                b=i;
                break;
            }
        }
        cout<<a*b<<endl;
    }
	return 0;
}
