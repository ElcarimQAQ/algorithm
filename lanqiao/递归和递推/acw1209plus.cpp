#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10],b[10],vis[10];
set<int> mp;
int n,aa,bb,cc,ans = 0;

int cal(int l,int r,int num[]){
    int res = 0;
    while(l < r){
        res = res *10 + num[l];
        // cout<<res<<endl;
        l++;
    }
    return res;
}

void dfs2(int cnt,int l){
    if(cnt > l)
        return;
    for(int i =1;i <= 9;++i){
        if(vis[i])
            continue;
        b[cnt] = i;
        vis[i] = 1;
        int bb = cal(0,cnt + 1,b);
        // if(aa == 3 && bb == 69258){
        //     cout<<aa<<" "<<bb<<" "<<(n - aa) / bb<<endl;   
        //     system("pause");
            
        //     }
        if(bb % (n - aa) == 0){
            cc = bb/ (n - aa) ;
            mp.clear();
            while(cc > 0){
                int pos = cc % 10;
                if(vis[pos] || mp.find(pos) != mp.end() ||pos == 0)
                    break;
                mp.insert(pos);
                cc /= 10;
            }
            if(cc == 0){
                int cnt_vis = 0;
                for(int j = 1;j <= 9; ++j){
                    if(vis[j] == 0)
                        cnt_vis++;
                }
                if(cnt_vis == mp.size()){
                    ans++;
                    // cout<<aa<<" "<<bb<<" "<<bb/(n - aa)<<endl;
                    // cout<<cnt_vis<<mp.size()<<endl;
                }
            }
        }
        dfs2(cnt + 1,l);
        vis[i] = 0;
    }
}

void dfs(int cnt,int l)
{
    if(cnt > l){
        return ;
    }
    for(int i = 1;i <= 9; ++i){
        if(vis[i])
            continue;
        a[cnt] = i;
        aa = cal(0,cnt + 1,a);
        // cout<<aa<<endl;
        if(aa >= n)
            continue;
        vis[i] = 1;
        dfs2(1,9 - cnt);
        dfs(cnt + 1,l);
        vis[i] = 0;
    }
}

int main()
{
    cin>>n;
    int m = n,cnt = 0;
    while(m > 0){
        cnt++;
        m /= 10;
    }
    dfs(1,cnt);
    cout<<ans<<endl;
    return 0;
}