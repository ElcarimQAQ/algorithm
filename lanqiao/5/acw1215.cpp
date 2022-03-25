#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int h[maxn],tr[maxn];
int vis[maxn];
int mi[maxn],sum[maxn];
int lowbit(int x){
    return x & (-x);
}

void update(int x,int v){
    for(int i = x;i < maxn;i += lowbit(i)){
        tr[i] += v;
    }
}

int querry(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}

int cnt[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>h[i]; 
        h[i]++;
    }
    for(int i = 1;i <= n;i++){
        
        vis[h[i]]++;
    }
    for(int i = 1;i < maxn;++i) mi[i] = mi[i-1] + vis[i];
    // for(int i = 1;i < 10;++i) cout<<vis[i] << " ";cout<<endl;
    long long ans = 0;
    for(int i = 1; i <= n;i++){
        int qm = i - 1 - querry(h[i]);
        int lm = mi[h[i] - 1] -  querry(h[i] - 1);
        // cout << mi[h[i]] << " " << vis[h[i]] <<endl;
        update(h[i],1);
        cnt[i] = lm +qm;
        ans += (long long)cnt[i] * (cnt[i] + 1) / 2;
        // cout<<ans<<" "<<qm<<" "<<lm<<" "<<endl;
    }
    // for(int i = 1;i <= n; i++){
    //     sum[i] += i - 1 - querry(h[i]);
    //     update(h[i],1);
    // }
    // memset(tr,0,sizeof(tr));
    // for(int i = n;i >= 1;i--){
    //     sum[i] += querry(h[i] - 1);
    //     update(h[i],1);
    // }
    // for(int i = 1;i <= n; i++)
    //     ans += (long long)sum[i] * (sum[i] + 1) / 2;
    cout << ans <<endl;
    return 0;
}