#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100005;
vector<int> f[maxn];
int vis[maxn];
int ans[maxn];

int main()
{
    int t,n,m,k;
    cin>>t;
    while (t--)
    {
        pair<int,int> so[maxn]; 
        cin>>n>>m;
        int ff,flag = 1;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for(int i = 1; i <= m; i++){
            f[i].clear();
            cin>>k;
            so[i].first = k;
            so[i].second = i;
            for(int j = 1;j <= k; j++){
                cin>>ff;
                f[i].push_back(ff);
            }
        }
        sort(so + 1,so + m + 1);
        // for(int i = 1;i <= m;i++)
        //     cout<<so[i].second<<endl;
        // cout<<"**"<<endl;
        int no = INF;
        int po = 0;
        for(int c = 1;c <= m ;c++){
            int i = so[c].second;
            if(f[i].size() == 1)
                po = f[i][0];
            else{
                no = INF;
                for(int j = 0;j < f[i].size(); j++){
                    int v = f[i][j];
                    if(vis[v] < no){
                        no = vis[v];
                        po = v;
                    }
                }
            }
            ans[i] = po;
            vis[po]++;
            if(vis[po] > (m + 1) / 2){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            for(int i = 1;i <= m - 1; i++)
                cout<<ans[i]<<" ";
            cout<<ans[m]<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}