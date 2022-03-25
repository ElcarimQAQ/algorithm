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
    string s;
    cin>>k;
    if(k==0)
        cout<<")("<<endl;
    else{
        a=sqrt(k);
        k=k-a*a;
        s.assign(a,'(');
        s.append(a,')');
        b=a*2;
        //cout<<s<<endl;
        while(k > 0){
            a=sqrt(k);
            s.insert(a,a,')');
            k=k-a*a;
            b+=a;
            //cout<<s<<endl;
        }
        cout<<s<<endl;
    }
    //cout<<b<<endl;
}
