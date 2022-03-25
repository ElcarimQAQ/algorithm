#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int a[maxn];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int f = 0; 
        for(int i = 1;i <= n;i++){
            cin>>a[i];
            if(i != 1){
                if(a[i] >= a[i-1])

            }
        }
        cout<<"-1"<<endl;
    }
    return 0;
}
