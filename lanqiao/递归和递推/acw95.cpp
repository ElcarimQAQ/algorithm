#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

int f[6][6];
string s[6];

int main()
{
    int n,ans,mi;
    cin>>n;
    while(n--){
        mi = 8;
        ans = 0;
        for(int i= 0;i < 5; ++i)
            cin>>s[i];
        for(int t = 0;t < (1<<6); ++t){
            int m = t,ans =0;
            // if(t == 16)cout<<'?'<<endl;
            for(int i =0;i < 5; ++i){
                for(int j = 0;j < 5;++j)
                    f[i][j] = s[i][j] - '0';
            }
            for(int i = 0;i < 5; i++){
                if(m >> i & 1){
                    f[0][i] ^= 1;
                    ans++;
                    for(int k = 0;k < 4; ++k){
                        int x = 0 + dir[k][0];
                        int y = i + dir[k][1];
                        if( 0 <= x && x< 5 && y >= 0 && y < 5)
                            f[x][y] ^= 1;        
                    }
                }
            }
            if(ans > 6)
                continue;
            // for(int i = 0;i < 5; ++i)
            //     cout<<f[0][i]<<" ";
            // cout<<endl<<ans<<endl;
            for(int i = 1;i < 5; i++)
            {
                for(int j = 0;j < 5; j++){
                    if(f[i - 1][j] == 0){
                        f[i][j] ^= 1;ans++;
                        for(int k = 0;k < 4; ++k){
                            int x = i + dir[k][0];
                            int y = j + dir[k][1];
                            if( 0 <= x && x< 5 && y >= 0 && y < 5)
                                f[x][y] ^= 1;        
                        }
                    }
                }
            }
            int cnt = 0;
            // for(int i = 0;i < 5; ++i)
            //     cout<<f[4][i]<<" ";
            // cout<<endl<<endl;
            for(int j = 0;j < 5; ++j){
                if(f[4][j] == 1)
                    cnt++;
                if(cnt == 5) mi = min(ans,mi);
            }
        }
        if(mi > 6) cout<<-1<<endl;
        else cout<<mi<<endl;
    }
    return 0;
}