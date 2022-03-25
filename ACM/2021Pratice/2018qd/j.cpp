#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
typedef long long ll;
ll a[maxn];

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        int f = 0;
        ll sum = 0,mi = 0;
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(int i = 1;i <= n; i++){
            cin>>a[i];
            if(!a[i]) mi++;
        }
        if(m == 0){
            sort(a + 1,a + 1 + n);
            cout<<a[1] - 1<<endl;
            continue;
        }
        if(m < mi){
            cout<<"Impossible"<<endl;
            continue;
        }
        for(int i = 1;i <= max(n,m+1); i++){
            if(i > n && mi == m){
                f = 1;
                break;
            }
            if(a[i] == 0 &&  i<= n)
                continue;
            if(++mi <= m){
                sum += a[i];
                continue;
            }
            sum += a[i] -1;
            break;
        }
        if(f == 1)
            cout<<"Richman"<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
