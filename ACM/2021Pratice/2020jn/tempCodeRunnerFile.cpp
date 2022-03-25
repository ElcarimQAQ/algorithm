#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
const int mod = 998244353;
typedef long long ll;
typedef int itn;

ll qpow(ll a,ll b,ll m){
    ll res = 1;
    while(b){
        if(b & 1)  res = res * a % mod;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

bitset<maxn> a[maxn];
int A[maxn][maxn],B[maxn][maxn];

ll guass(int n,int m)
{
    int row = 0,col = 0,maxx;
    for(; col < m && row < n ;++ col){
        for(maxx = row ;maxx < n;++maxx){
            if(a[maxx][col])
                break;
        }
        if(a[maxx][col] == 0)
            continue;

        swap(a[maxx],a[row]);
        for(int i = row + 1;i < n; ++i){
            if(a[i][col])
                a[i] ^= a[row];
        }
        row++;
    }
    return qpow(2,n - row,mod);
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

        // for(int i = 0;i < n; ++i){
        //     for(int j = 0;j < n; ++j)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }   

        for(int i =0;i < n; ++i)
            a[i][i] = (A[i][i] ^ B[i][j]);

        // for(int i = 0;i < n; ++i){
        //     for(int j = 0;j < n; ++j)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }
        ll tem = guass(n,n);
        for(int i = 0;i < n; ++i){
            for(int j = 0;j < n; ++j)
                cout<<a[i][j]<<" ";
            cout<<endl; 
        }
        cout<<tem<<endl;
        ans = ans * tem % mod; 
    }
    cout<<ans<<endl;
    return 0;
}