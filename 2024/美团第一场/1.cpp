#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> ma;

int main() {
    int n;
    cin>>n;
    int sum0[205][205];
    string s;
    for(int i = 1;i <= n; i++){
        cin>>s;
        // ma.push_back(s);
        int cnt = 0;
        for(int j = 1;j <= n; j++){
            if (s[j-1] == '0') cnt++; 
            sum0[i][j] = sum0[i-1][j] + cnt;
            // cout<<sum0[i][j]<<' ';
        }
    }
    int num0 = 0;
    int num1 = 0;
    cout<<0<<endl;
    for(int i = 1;i < n; i++){
        int ans = 0;
        for(int si = 1;si <= n; si++){
            for(int sj = 1; sj <= n; sj++){
                int ei = si + i;
                int ej = sj + i;
                if(ei > n || ej > n) break;
                num0 = sum0[ei][ej] + sum0[si-1][sj-1] - sum0[si-1][ej] - sum0[ei][sj-1];
                num1 = (i+1) * (i+1) - num0;
                if(num0 == num1){
                    ans++;
                    // cout<<'i is :'<<i<<'\n';
                    // cout<<si<<' '<<sj<<' '<< ei<<' '<<ej<<"\n";
                }
            }
        }
        cout<<ans<<"\n";
    }

}
