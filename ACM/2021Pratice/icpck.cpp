#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 1000000007
const int inf=1<<30;
ll l[maxn];

int main()
{
    int t,a,b,n;
    cin>>t;
    for(int c = 1; c <= t ; c++ ){
        cin>>a>>b>>n;
        for(int i = 1; i <= a; i++)
            scanf("%lld",&l[i]);
        ll x,y,lx;
        x = a;
        y = b;
        while(n--){
            if(x == lx)
                break;
            lx = x;
            y = x;
            x = 1;
            for(int i = 1; i <= x;i++){
                if(y > l[i]){
                    y -= l[i];
                    x++;
                }
                else
                    break;
            }
            if(x == 1 && y == 1)
                break;
        }
        printf("Case #%d: %lld-%lld\n",c,x,y); 
    }
    return 0;
}