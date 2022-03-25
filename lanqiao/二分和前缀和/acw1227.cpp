#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
typedef pair<int ,int> PII;
const  int maxn = 5e5+5;
int h[maxn],w[maxn];
int n,k;

int check(int m)
{
    int ans = 0;
    for(int i = 1;i <= n; ++i){
        int x = h[i] / m;
        int y = w[i] / m;
        ans +=  x * y;
    }
    if(ans >= k)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>k;
    for(int i = 1;i <= n; ++i)
        cin>>h[i] >> w[i];
    int l = 0,r = 1e5+5;
    while(l < r){
        int m = (l + r) >> 1;
        if(check(m)) l = m + 1;
        else 
            r = m;
    }
    cout<<r-1<<endl;
    return 0;
}