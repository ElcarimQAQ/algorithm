#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;

const int mxm=2e5+5;
const ll N=1e10+5;

bool isprime[mxm];
ll prime[mxm],w[mxm],id1[mxm],id2[mxm];
ll num_pri=0;
ll m=0;
ll sump[mxm];
__int128 g[mxm];
__int128 cal(ll x){
    return (__int128)x*(x+1)/2-1;
}
ll sqr;
ll n,mod;
ll id3(ll x){
    return x<=sqr?id1[x]:id2[n/x];
}
ll f(int x){
	return 1;
}
void el(){
    sqr=sqrt(N);
    isprime[1]=1;
    for(ll i=2;i<=sqr;++i){
        if(!isprime[i]) prime[++num_pri]=i,sump[num_pri]=sump[num_pri-1]+f(prime[num_pri]);
        for(ll j=1;j<=num_pri&&i*prime[j]<=sqr;++j){
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }//线性筛预处理 筛出素数 和 f(素数)的前缀和 
}//正常 
void init(){
    for(ll i=1;i<=n;i=n/(n/i)+1){
        w[++m]=n/i;
        if(w[m]<=sqr){
            id1[w[m]]=m;
        }
        else{ 
            id2[n/w[m]]=m;
        }//记录id 
        //g[m]=w[m]*(w[m]+1)/2-1;//初始化g 
        g[m]=w[m]-1;//2到w[m]所有f(x)的和 
    }
    for(ll i = 1;i<=num_pri;++i){
        for(ll j=1; j<=m && 1ll*prime[i]*prime[i] <= w[j]; ++j){
            g[j]=g[j] - (__int128) f(prime[i])* (g[id3(w[j] / prime[i])] - sump[i - 1]);
        }
    }
}
int main(){
    el();
    int t;
    cin>>t;
    for(int i = 1 ;i<= n; i++){
    	cin>>n;
		 m=0;
        init();

        ll answer = g[id3(n)] ;
        
        printf("%lld\n",  (ll)answer +1);
	}
    return 0;
}