#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int ww = 0,ll = 0,tt = 0;

int judge(int x)
{
    int l = 0,w = 0,t = 0;
    if(x == 8 || x >= 10)
        return 0;
    if(x != 3){
        l = x % 3;
        w = x / 3;
        t = x - l - w;
        ww += w;
        ll += l;
        tt += t;
    }
    else 
    {
        w = 1,l = 2,t = 0;
        ww += w;
        ll += l;
        tt += t;
    }
    return 1;
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t,a,b,c,d;
    cin>>t;
    for(int cas =1;cas <=t ;cas++){
        cin>>a>>b>>c>>d;
        int f = 1;
        f &= judge(a);
        f &= judge(b); 
        f &= judge(c);
        f &= judge(d); 
        if(f)
            cout<<"Wrong Scoreboard"<<endl;
        else if(ww == ll && ww + tt +ll == 6)
            cout<<"Yes"<<endl;

    }
    // system("pause");
    return 0;
}