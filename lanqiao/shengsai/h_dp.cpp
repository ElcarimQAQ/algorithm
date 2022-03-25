#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
map<char,int> last;
int dp[maxn];

int main()
{
    string s;
    ll ans = 0;
    cin>>s;
    dp[0] = 1;
    last[s[0]] = 0;
    for(int i = 1;i < s.length(); i++){
        if(last.find(s[i]) == last.end()){
            dp[i] = dp[i - 1] + i  +1; 
            last[s[i]] = i;
        }
        else{
            dp[i] = dp[i - 1] + i - last[s[i]];
            last[s[i]] = i;
        }
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    for(int i = 0;i < s.length(); ++i)
        ans += dp[i]* 1ll;
    cout<<ans<<endl;
    return 0;
}