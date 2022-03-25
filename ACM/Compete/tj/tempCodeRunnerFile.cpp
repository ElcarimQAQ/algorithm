#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll p[maxn];
ll ans[maxn];
int cnt = 0;

bool Is_prime(ll n)
{
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0) return false;
    }
    return true;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n == 0)
        cout<<0<<endl;
    else{
        int j = 0;
        for(ll i = 2;i <= n;i++){
            if(Is_prime(i))
                p[++j] = i;
        }
        j = 1;
        int k = 0;
        while(n > 1){
            while(n % p[j] == 0){
                ans[++k] = p[j];
                n /= p[j];
            }
            if(n <= 1)
                break;
            j++;
        }
        cout<<j<<endl;
        for(ll i = 1;i < k;i++)
            cout<<ans[i]<<" ";
        cout<<ans[k]<<endl;
    }
     return 0;
}
