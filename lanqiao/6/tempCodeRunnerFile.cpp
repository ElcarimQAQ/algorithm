#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
int a[maxn],b[maxn];
int vis[maxn];

int main()
{   
     int n,x;
     cin>>n;

         for(int i = 1; i <= n; ++i){
             cin>>a[i];
         }
         int ans = 0;
         for(int i = 1; i <= n;i++){
             if(!vis[i]){
                 ans++;
                 for(int j = i; !vis[j]; j = a[j]){
                     vis[j] = 1;
                 }
             }
         }
        cout<<ans<<endl;

     
    return 0;
}