// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 5e6+5;
int a[maxn],dp[maxn];
vector<int> g[maxn];

int  dfs(int x,int cnt,int fa)
{
    if(g[cnt][0] == 0 && g[cnt][1] == 0){
        if(x < fa) g[cnt][0] = x;
        if(x > fa) g[cnt][1] = x;
        return 1;
    }
    if(x < fa)
        g[cnt][0] = x;
    if(g[cnt][1] == 0 && x > fa)
        g[cnt][1] = x;
    
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        dfs(a[i],1,a[1]);
        
    }
    return 0;
}