#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
#define INF 0x3f3f3f3f
typedef long long ll;
int a[maxn],b[maxn];

int gcd(int m,int n){
    if(n == 0) return m;
    return gcd(n, m % n);
}

int main()
{
    int n,m;
    cin>>n;
    int f = 1;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        if(a[i] != a[1])
            f = 0;
    }
    if(f) {
        cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; ++i)
        b[i - 1] = abs(a[i] - a[i - 1]);
    // cout<<gcd(70,20);
    int ans = b[1];
    for(int i = 1;i < n;i++){
        // cout<<b[i]<<" "<<ans<<" ";
        ans = gcd(b[i],ans);
        // cout<<ans<<endl;
    }
    cout<<abs(a[n] - a[1]) / ans + 1<<endl;
    return 0;
}