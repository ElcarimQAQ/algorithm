#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 1e9;
typedef long long ll;

int main()
{
   
    int t,h;
    cin>>t;
    while(t--){
        cin>>h;
        int ans = 0;
        int cnt = 1;
        while(h){
            if(h & cnt){
                ans++;
                h -= cnt;
            }
            else {
                ans += 2;
                h -= 2*cnt;
            }
            cnt <<= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}