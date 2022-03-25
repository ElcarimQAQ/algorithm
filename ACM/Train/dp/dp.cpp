#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[20][20];
int a[20];
int len;

ll dfs(int pos,int pre,int lead,int limit){//pos数字位置，pre记录前位,st记录答案，lead判断前导0，limit限制最高位
    if(pos > len) return 1;//剪枝
    if((dp[pos][pre]!= 1) && !limit && !lead) return dp[pos][pre];//记录当前值
    ll ret = 0;//当前方案数
    int res = limit ? a[len - pos + 1] : 9; //res当前位能取到的最大值
    for(int i = 0; i <= res; i++){
        if(abs(i - pre) < 2) 
            continue;
        if(!i && lead ) ret += dfs(pos + 1,-2,1,i == res && limit );//是0的时候如果不限制前导0
        else  res += dfs( pos + 1,i,0,i == res && limit );
    }
    if(!limit && !lead) dp[pos][pre] = ret;
    return ret;
}

ll part(ll x){//把数按位拆分
    len = 0;
    while(x) a[++len] = x % 10,x /= 10;
    memset(dp,-1,sizeof(dp));
    return dfs(1,-2,1,1);
}

int main()
{
    ll l,r;
    cin>>l>>r;
    cout<<part(r) - part(l - 1) << endl;
    return 0;
}