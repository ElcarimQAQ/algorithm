#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
#define PII pair<int,int>
#define INF 0x3f3f3f3f
PII a[maxn];
int num[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int  n,m,k,j,cnt = 0;
    cin>>n>>m;
    for(int i = 1;i <= n ;i++){
        cin>>k;
        while(k--){
            cin>>j;
            a[++cnt] = make_pair(j,i);
        }
    }
    sort(a + 1,a + 1 + cnt);
    int l = 1,r = l,sum = 0,ans = INF;
    num[a[l].second]++;
    sum++;
    while(r <= cnt){
        while(sum < m){
            r++;
            if(!num[a[r].second])
                sum++;
            num[a[r].second]++;
        }
        if(r > cnt)
            break;
        // cout<<l<<" "<<r<<endl;
        ans = min(ans,a[r].first - a[l].first);
        num[a[l].second]--;
        if(num[a[l].second] == 0)
            sum--;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}