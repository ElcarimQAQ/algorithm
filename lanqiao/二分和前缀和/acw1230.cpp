#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
typedef pair<int ,int> PII;
const  int maxn = 5e5+5;
ll a[maxn],l[maxn];
ll cnt[maxn];
int n,k;

int main()
{
    cin>>n>>k;
    ll ans = 0;
    cnt[0] = 1;
    for(int i = 1;i <= n; ++i){
        cin>>a[i];
        l[i] = l[i - 1] + a[i];
        ans += cnt[l[i] % k];
        cnt[l[i] % k]++;
    }   
    cout<<ans<<endl;
    return 0;
}