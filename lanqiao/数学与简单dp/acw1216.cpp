#include<bits/stdc++.h>
using namespace std;
const int maxn  = 55;
int a[maxn];

int main()
{
    int n,ans;
    cin>>n;
    ans = n;
    while(n >= 3){
        int cnt = n / 3;
        ans += cnt ;
        n = cnt + n % 3;
    }
    cout<<ans<<endl;
    return 0;
}