#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=60005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
pair<int,int> no[maxn];
int dp[maxn][2];
int t[maxn];
int cal(pair<int,int> a,pair<int,int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    // ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++)
        cin>>t[i]>>no[i].first>>no[i].second;
    for(int i = 1;i <= m; i++){
        for(int j = i-1;j >= 0; j--){
            dp[i][0] = max(dp[i][0], max(dp[j][1],dp[j][0]));
            if((t[i] - t[j] >= cal(no[i],no[j]) || j == 0)){
                dp[i][1] = max(dp[i][1],dp[j][1]+1);
                break;
            }
        }
    }
    cout<<max(dp[m][1],dp[m][0])<<endl;
    return 0;
}