// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 20005;
int a[maxn],b[maxn],c[maxn];

int main(){
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;++i)
        cin>>a[i];
    int ma = 0;
    for(int i = 1;i <= n;++i){
        cin>>b[i];
        c[i] = a[i ] + b[i]; 
        ma =max(ma,c[i]);
    }
    for(int )
    return 0;
}