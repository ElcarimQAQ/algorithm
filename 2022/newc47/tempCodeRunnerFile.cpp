#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const double PI =  3.141592653589;
const int maxn = 2e5+5;
const ll mod =  1e9+7;
int a[maxn];

int main() 
{
    int n, cute;
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++)   
        cin>>a[i];
    cin >> cute;
    int t = 0;
    int last = n + 1;
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if (a[i] > cute) {
            t++;
            if(i < t){
                ans = t - 1 + (last -  i);
                break;
            }
            last = i;
        }
    }
    if(last == n + 1)
        ans = n+1;
    cout<<ans<<endl;
    return 0;
}