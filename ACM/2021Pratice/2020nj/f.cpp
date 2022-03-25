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
#define eps 1e-9
const int inf=1<<30;
double n,m,p;
int ans ;
double val(double x){
    return (x * n + m)*1.0 / (1.0-pow(1.0-p,x));
}

inline void sanfen()
{
    double l = 0.0,r = 1e9;
    double lmid,rmid;
	while(r - l > eps)
	{
		lmid = l + (r - l) / 3.0;
		rmid = r - (r - l) / 3.0;
		if(val(lmid) > val(rmid)) l = lmid;
		else r = rmid;
	}
    ans = l;
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        p = p * 0.0001;
        sanfen();
        // ans = min(val(ans), val(ans+1));
        printf("%.10lf\n",min(val(ans), val(ans+1)));
    }
    return 0;
}