#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 100005;
typedef long long ll;
ll a[maxn];
ll cf[maxn];
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 1; i <= n;i++){
            cin>>a[i];
            cf[i] = a[i] - a[i - 1];
        }
        int f =1;
        int cnt = 0;
        for(int i = n;i >= 1; i--){
            if(cf[i] >= 0 && i > k - 1){
                cnt++;
                cf[i - k] += cf[i];
                cf[i] = 0;
            }
        }
        if(f == 0)
            cout<<"-1"<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}