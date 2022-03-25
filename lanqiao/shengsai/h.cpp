#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
int l[maxn][25];

int main()
{
    string s;
    int ans = 0,cnt = 0;
    cin>>s;
    for(int i = 0;i <s.length(); ++i){
        if(i != 0)
            for (int j = 0; j < 25; j++)
                l[i][j] = l[i - 1][j];
        l[i][s[i] - 'a']++;
    }
    // for(int i= 0;i < s.length() ;i++){
    //     for (int j = 0; j < 25; j++)
    //     {
    //         cout<<l[i][j]<<" ";
    //     }
    //     puts("");
    // }
    for(int i = 0;i < s.length(); i++){
        for (int j = i ;j <s.length(); ++j){
            cnt = 0;
            for(int k = 0;k < 25 ;k++){
                if(l[j][k] == 0)
                    continue;
                if(i == 0)
                    cnt++;
                else if(l[j][k] - l[i - 1][k] > 0)
                    cnt++;
            }
            // cout<<cnt<<endl;
            ans += cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}