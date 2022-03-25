#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
#define INF 0x3f3f3f3f
typedef long long ll;
set<ll> ans;
vector<ll> t[maxn];
ll tot[maxn];

int main()
{
    ll n,d,k,ts,id;
    cin>>n>>d>>k;
    while(n--){
        cin>>ts>>id;
        t[ts].push_back(id);
    }
    for(ll l = 0; l + d - 1< maxn ;l++){
        ll r  = l + d - 1;
        if(l == 0){
            for(ll i = 0;i <= r;i++){
                for(auto j : t[i]){
                    tot[j]++;
                    if(tot[j] >= k) ans.insert(j);
                }
            }
            
        }
        else{
            for(auto j : t[l - 1])
            {
                tot[j]--;
            }
            for(auto j : t[r]){
                tot[j]++;
                if(tot[j] >= k) ans.insert(j);
            }
        }
    }
    for(auto i: ans)
        cout<<i<<endl;
    return 0;
}