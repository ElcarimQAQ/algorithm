#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
set<ll> vis;


ll slove(ll s){
    ll ans = 1;
    ll cnt = 0;
    ll x = s;
    for( ll i = 2; i <= sqrt(s);i++){    
        while(x % i == 0){
            x /=  i;
            cnt++;
        }
        ans = ans*(cnt + 1);
        cnt = 0;
    } 
    if(x != 1) ans *= 2; 
    return ans;
}



int main()
{
    ll q,n;
    cin>>q>>n;
    ll sum = 0;
    if(q == 1){
        sum = slove(n);
    }
    else{
        for(ll a = 1 ;a  < n; a++){
            vis.clear();
            ll cnt = 0;
            for (ll x = 1; x <= (n - 1)/ a;x++ ){
                ll by = n - a*x;
                for( ll i = 1 ;i<= sqrt(by);i++){
                    if(by % i ==0){
                        if(vis.find(i) == vis.end()){
                            cnt++;
                            // cout<<a << " "<<i<<endl;
                        }
                        vis.insert(i);
                        if(vis.find(by/i) == vis.end()){
                            cnt++;
                            // cout<<a << " "<<by/i<<endl;
                        }
                        vis.insert(by/i);
                        // vis[by /i] = 1;
                    }
                }
            }
            sum += cnt;
        }
    }
    cout<<sum<<endl;
    return 0;
}