#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 100005;

vector<ll> ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n == 0)
        cout<<0<<endl;
    else{
        int j = 0;
        for(ll i=2;i*i<=n;++i)
        {
            if(n%i==0){
                ans.push_back(i);
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1)
            ans.push_back(n);
        cout<<ans.size()<<endl;
        for(int i = 0;i < ans.size()-1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[ans.size() - 1]<<endl;
    }
     return 0;