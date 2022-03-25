#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e3+7;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
__int128 dp[1<<22]; 
int a[25],b[25];

inline void print(__int128 x){//输出模板 
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) dp[1 << i] = a[i] * m + b[i];
    for (int i = 0; i < (1 << n); i++) {//枚举开始的机器人的使用状态
        for (int k = 0; k < n; k++) {
            if (!((i >> k) & 1)) {//第k位的机器人未被使用
                dp[i | (1 << k)] = max(dp[i | (1 << k)], dp[i] * a[k] + b[k]);
            }
        }
    }
    print(dp[(1 << n) - 1]);
    return 0;
}