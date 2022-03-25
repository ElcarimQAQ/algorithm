#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int p[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i<= n; i++)
        cin>>p[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int mi = p[i],ma = p[i];
        ans += 1;
        for(int j = i + 1 ; j <= n; j++){
            if(p[j] > ma)
                ma = p[j];
            if(p[j] < mi)
               mi = p[j];
            if(ma - mi == j - i )
                ans += 1;
        }
    }
    cout<<ans <<endl;
    return 0;
}