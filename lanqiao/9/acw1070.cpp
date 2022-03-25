#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
int f[maxn][maxn];

int check(char x,char y){
    if(x =='[' && y==']') return 1;
    if(x =='(' && y==')') return 1;
    return 0;
}
int main()
{   
    string s;
    cin>>s;
    // cout<<s<<endl;
    int ans = 0;
    for(int len = 2;len <= s.length() ;len++){
        for(int l = 0;l + len - 1 < s.length();l++){
            int r = l + len - 1;
            if(check(s[l],s[r])) {
                // cout<<"?"<<endl;
                // cout<<s[l]<<"?"<<s[r]<<endl;
                if(r - l == 1) {
                    f[l][r] = 1;
                }
                f[l][r] |= f[l + 1][r - 1];
                for(int k = l + 1;k < r-1; k++){
                    f[l][r] |= (f[l][k] & f[k+1][r]);
                }
                if(f[l][r])  ans = max(ans,len );
            }
        }
    }
    cout<<s.length() - ans<<endl;
    return 0;
}