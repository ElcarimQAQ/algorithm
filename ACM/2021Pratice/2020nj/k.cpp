#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int p[maxn];
int l[maxn],r[maxn];

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ans;
    if(k == 0)
        cout<<-1<<endl;
    else{
        if(k & 1){
            for(int i = 1;i <= k;i++){
                if(i == 1)
                    cout<<1<<" ";
                else{
                    if(i % 2 == 0)
                        cout<<i+1<<" ";
                    else
                        cout<<i-1<<" ";
                }
            }
        }
        else{
            for(int i = 1;i <= k;i++){
                if(i%2){
                    cout<<i+1<<" ";
                }
                else
                    cout<<i-1<<" ";
            
            }
        }
        for(int i = k+1;i<= n;i++){
            if(i == n)
            cout<<i<<endl;
            else
                cout<<i<<" ";

        }
    }
    return 0;
}