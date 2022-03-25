#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll sum = 0,ans = 0;
        for(int i = 1;i <= n; i++){
            cin>>a[i];
            sum += a[i];
            if(sum % i == 0)
                ans = max(ans,sum / i);
            else
                ans = max(ans,sum / i + 1); 
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}