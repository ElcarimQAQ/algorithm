#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int a[maxn],b[maxn];
#define INF 0x3f3f3f3f
int t,n,k,cnt = 0;


int main()
{
    cin>>t;
    while(t--){
        cnt = 0;
        cin>>n>>k;
        for(int i = 1;i <= n;i++)
            cin>>a[i];
        for(int i = 1;i <= n;i++){
            if(a[i] < k) {
                cnt += a[i];
                k -= a[i];
                a[i] = 0;
            }else {
                cnt += k;
                a[i] -= k;
                break;
            }
        }
        a[n] += cnt;
        for(int i =1;i <= n; i++)
            cout<<a[i] <<" ";
        cout<<endl;
    }
    return 0;
}
