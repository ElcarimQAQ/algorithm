#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int dp[maxn];

int main()
{
    int n,ans = 0;
    cin>>n;
    for(int i =1 ;i <= n; i++)
        cin>>a[i];
    for(int i =1;i <= n;i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++ ){
            if(a[i] > a[j]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    for(int i = 1;i <= n; i++)
        ans = max(dp[i],ans);
    cout<<ans<<endl;
    return 0;
}