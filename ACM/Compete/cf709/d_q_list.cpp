#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
#define  PII pair<int,int>
deque<int> q;
vector<int> ans;

int nex[maxn],a[maxn],vis[maxn];
int gcd(int a,int b){
    return b == 0 ? a:gcd(b,a % b);
}


int main()
{
    ios::sync_with_stdio(false);
    int t,n,j,cnt,pos;
    PII x1,x2;
    cin>>t;
    while(t--){
        cnt  = 0;
        q.clear();
        ans.clear();
        cin>>n;
        for(int i = 1;i <= n; i++){
            cin>>j;
            a[i] = j;
            nex[i - 1] = i;
            q.push_back(i);
            vis[i] = 0;
        }
        nex[n] = 1;
        while(!q.empty()){
            int x = q.front();q.pop_front();
            // cout<<x<<endl;
            if(vis[x])
                continue;
            if(gcd(a[x],a[nex[x]]) == 1){
                ans.push_back(nex[x]);
                vis[nex[x]] = 1;
                nex[x] = nex[nex[x]];
                q.push_back(x);
            }
        }
        cout<<ans.size()<<" ";
        for(auto i : ans)
            cout<<i <<" ";
        cout<<endl;
    }

    return 0;
}