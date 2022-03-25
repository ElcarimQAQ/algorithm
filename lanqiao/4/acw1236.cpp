#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn],b[maxn],c[maxn];
int vis1[maxn],vis2[maxn];
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i<= n;i++)
        cin>>b[i];
    for (int i = 1; i <= n; i++)
        cin>>c[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
    int i =n,j = n;
    while(i >= 1 && j >= 1){
       if(a[i] < b[j]){
           vis1[j] = i;
           j--;
       }
       else{
            i--;
        }
    }
    // for(;j >= 1;--j){
    //     vis1[j] = i;
    //     // cout<<vis1[j]<<endl;
    // }
    i =1,j = 1;
    while(i <= n && j <= n){
       if(b[i] < c[j]){
           vis2[i] = j;
           i++;
       }
       else
            j++;
    }
    // cout<<i<<" "<<j<<vis2[i]<<endl;
    for(i;i <= n;i++){
        vis2[i] = n+1;
        // cout<<vis2[i]<<endl;
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++ ){
        // cout<<vis1[i]<< (n - vis2[i] + 1)<<endl;
        ans += 1ll * vis1[i]* (n - vis2[i] + 1);

    }
    cout<<ans<<endl;
    return 0;
}