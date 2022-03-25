// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int a[10],l[10],r[10];

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        r[n + 1] = INF;
        for(int i = 1;i <= n; i++){
            cin>>a[i];
            l[i] = max(a[i],l[i - 1]);
        }
        for(int i = n;i >= 1; i--){
            r[i] = min(a[i],r[i + 1]);
        }
        int f = 0;
        for(int i = 2;i< n; i++){
            if(l[i-1] > r[i + 1] && l[i - 1] > a[i] && a[i]  < r[i + 1]){
                f =1;break;
            }
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}