#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
int a[maxn];
int f[maxn][10005];
int  gcd(int m,int n)
{
    if(n == 0) return m;
    return gcd(n,m%n);
}

int main()
{   
    int n,cnt;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        if(i != 1){
            cnt = gcd(a[i],cnt);
        }
        else cnt = a[1];
    }
    if(cnt != 1){
        cout<<"INF"<<endl;
        return 0;
    }
    f[0][a[1]] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 10005;j++){
            f[i - 1][0] = 1;
            if(f[i - 1][j] == 0) continue;
            f[i][j] = f[i -1][j];
            for(int k = 1;j + k*a[i] <= 10005;k++)
                f[i][j + k*a[i]] = f[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= 10005; i++){
        if(!f[n][i]) {
            // cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}