#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int w[maxn];

int m;
int main()
{
    cin>>m;
    int ans;
    for(int i = 1 ; i <= m; i++)
        cin>>w[i];
    sort(w + 1,w + m+1);
    int l = 1,r = m;
    ll sl = w[1],sr = w[m];
    while(l <= r){
        if(sl < sr){
            l++;
            sl += w[l];
        }
        else if(sr < sl){
            r--; 
            sr += w[r];
        }
        else{
            if(w[l] == w[r]){
                ans = w[l] ;
                break;
            }
            else if(l == r - 1){
                ans = w[l] + 1;
                break;
            }
            else if(l == r - 2){
                ans  = w[l+1];
                break;
            }
            else{
                 l++,r--;
                 sl += w[l];
                 sr += w[r];
            }
        }
    }
    cout << ans << endl;
    return 0;
}