#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e5+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f

int main ()
{
    int t,n;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>t;
     string b;
    while(t--){
        string a;
        cin>>n;
        cin>>b;
        for(int i=0;i<n;++i){
            //sum[i-1] = b[i-1]-'0'+a[i-1];
            a+='1';
            if(a[i]+b[i]==a[i-1]+b[i-1])
                a[i] = '0';
        }  
        cout<<a<<endl;                    
    }
	return 0;
}
