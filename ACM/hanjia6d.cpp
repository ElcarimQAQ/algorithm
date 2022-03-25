#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=2e6+7;
const int mod=998244353;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int num[maxn];

int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,cnt;
    while(cin>>n>>cnt){
        int ans = 0;
        memset(num,0,sizeof(num));
        for(int i = 1; i <=n ;i++){
            cin>>num[i];
            if(num[i] != cnt){
                ans =ans+num[i];
                ans %=11 ;
            }
        }
        if(n == 2)
            cout<<num[1]+num[2]-cnt<<endl;
        else
            cout<<ans%11<<endl;
    }
    return 0;
}
