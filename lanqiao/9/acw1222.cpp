#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int f[maxn][maxn];
#define INF 0x3f3f3f3f
int main()
{
    string ss ;
    cin >> ss ;
    //memset(f,-INF, sizeof(f));
    f[0][0] = 0;
    for(int len = 1; len <= ss.length() ; ++len) {
        for(int l = 0; l < ss.length(); l++)  {
            int r = l + len -1;
            if(len == 1) {
                f[l][r] = 1;
                continue;
            }
            if(ss[l] == ss[r]) 
                f[l][r] = f[l + 1][ r - 1] + 2;
            f[l][r] = max(f[l][r],f[l][r - 1]);
            f[l][r] = max(f[l][r], f[l + 1][r]);
            // cout<<f[l][r]<<endl;
        }
    }
    cout<<ss.length() - f[0][ss.length() - 1] <<endl;
    return 0;
}