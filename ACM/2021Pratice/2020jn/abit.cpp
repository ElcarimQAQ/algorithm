#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
const int mod = 998244353;
typedef long long ll;
typedef int itn;

bitset<maxn> a[maxn];
int A[maxn][maxn],B[maxn][maxn];

ll guass(int n,int m)
{
    int now = 0;
    for(int i = 0;i < n; ++i){
        int j = now;
        while(j < n && !a[j][i]) ++j;
        if(j == n + 1) continue;
        if(j != now) swap(a[now],a[i]);
        for(int k = 0; k < n; ++k)
            if(k != now && a[k][i]) a[k] ^= a[now];
        now++;
    }
    return  pow(2,n - now) % mod;
}

int main()
{
    int n;
    cin>>n;
    ll ans = 1;
    for(int i =0;i < n; ++i)
        for(int j = 0;j < n; ++j)
            cin>>A[i][j];
    for(int i = 0;i < n; ++i)
        for(int j = 0;j< n ; ++j)
            cin>>B[i][j];  
    for(int j = 0;j < n; ++j){
        for(int i = 0;i < n; ++i)
            for(int k = 0;k < n; ++k)
                a[i][k] = A[i][k];
        for(int i =0;i < n; ++i)
            a[i][j] = (A[i][i] ^B[i][j]);
        ans = ans * guass(n,n) % mod; 
    }
    cout<<ans<<endl;
    return 0;
}