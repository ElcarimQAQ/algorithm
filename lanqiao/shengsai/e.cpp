#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[8];
int a[8][8];
int vis[8],ans =0;
// abcdefg
// 1234567
void init(){
    a[1][6] = a[1][2] = 1;
    a[2][1] = a[2][7] = a[2][3] = 1;
    a[3][4] = a[3][7] = a[3][2] = 1;
    a[4][3] = a[4][5] = 1;
    a[5][4] = a[5][7] = a[5][6] = 1;
    a[6][1] = a[6][7] = a[6][5] = 1;
    a[7][6] = a[7][2] = a[7][3] = a[7][5] = 1;
}

int find(int x){
    if(pre[x] == x )
        return  x ;
    else return pre[x] = find(pre[x]);
}

void dfs(int pos)
{
    if(pos > 7){
        for(int i = 1;i <= 7; i++)
            pre[i] = i;
        for(int i = 1;i <= 7; i++){
            for(int j = 1;j <= 7; j++){
                if(a[i][j] && vis[i] && vis[j]){
                    int fa = find(i),fb = find(j);
                    // cout<< fa<<" "<<fb<<endl;
                    if(fa != fb)
                        pre[fa] = fb;
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i <= 7;++i){
            if(vis[i] && (pre[i] == i))
                cnt++;
        }
        if(cnt == 1){
            ans++;
            // for(int i = 1;i <= 7;++i)
            //     cout<<pre[i];
            // cout<<endl;
            // for(int i = 1;i <= 7;++i)
            //     if(vis[i]) cout<<i;
            // cout<<endl;
        }
        return;
    }
    vis[pos] = 1;
    dfs(pos + 1);
    vis[pos] = 0;
    dfs(pos + 1);
}
int main()
{

    init();
    dfs(1);
    cout<<ans<<endl;
    return 0;
}