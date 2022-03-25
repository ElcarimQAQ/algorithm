#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
ll dp[maxn];

int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    int a,b;
    cin>>k;
    if(k==0)
        cout<<")(";
    else{
        for(a=sqrt(k);a<=k;a++){
            if(k%a==0){
                b=k/a;
                break;
            }
        }
        if(a==k){
            cout<<"()";
            k=k-1;
            if(k!=0){
                for(a=sqrt(k);a<=k;a++){
                    if(k%a==0){
                        b=k/a;
                        break;
                    }
                }
                if(a+b<=100000){
                    for(int i = 0;i<a-1;i++ )
                    cout<<"(";
                    for(int i = 0;i<b;i++ )
                        cout<<")";
                }
            }
        }
        else{
            if(a+b<=10005){
                for(int i = 0;i<a;i++ )
                    cout<<"(";
                for(int i = 0;i<b;i++ )
                    cout<<")";
            }
        }
    }
    cout<<endl;
    cout<<a<<" "<<b<<endl;
    cout<<a+b<<endl;
}
