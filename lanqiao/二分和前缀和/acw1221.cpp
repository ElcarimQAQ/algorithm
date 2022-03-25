#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
typedef pair<int ,int> PII;
const  int maxn = 5e7+5;
int vis[maxn];
PII ha[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt =0;
    for(int i = 0;i * i <= n; ++i)
        for(int j = i;j * j + i * i <= n; ++j ){
            int t = j * j + i * i;
            if(vis[t] == 0) {
                ha[t] = {i,j};
                vis[t] =1;
            }
        }
    for(int i = 0;i * i <= n; ++i)
        for(int j = 0;j * j + i * i <= n; ++j ){
            int t = n - j * j - i * i;
            if(vis[t]){
                cout<<i<<" "<<j<<" "<<ha[t].first<<" "<<ha[t].second<<endl;
                return 0;
            }
        }
    
    return 0;
}