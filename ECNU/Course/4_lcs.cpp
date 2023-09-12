#include <bits/stdc++.h>
using namespace std;
 
string str1,str2;
 
int main()
{
    cin>>str1>>str2;
    int n = str1.size(), m = str2.size();
    int dp[n+1][m+1];
    memset(dp, 0 ,sizeof(dp));
    //动态规划找到最长公共子序列
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){  
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string res;
    int t1 = n , t2 = m ;
    cout<<dp[t1][t2]<<endl;
    while (t1 > 0  && t2 > 0) {
        if (str1[t1-1] == str2[t2-1]) {
            res += str1[t1 - 1];
            --t1;
            --t2;
        } else if (dp[t1-1][t2] > dp[t1][t2-1]) {
            --t1;
        } else 
            --t2;
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;
    return 0;
}