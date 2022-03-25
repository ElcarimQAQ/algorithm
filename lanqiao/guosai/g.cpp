#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 10005;
typedef long long ll;

set<string> st;
vector<string> a;
string vis[maxn];
int f[maxn];
int la[maxn];
stack<string> fans;
int main()
{
    string s,ss;
    cin>>s;
    ss= "";
    ss += s[0];
    for(int i = 1;i < s.length();i++){
        if( s[i] >= 'A' && s[i] <= 'Z'){
            st.insert(ss);
            a.push_back(ss);
            ss = ""; 
        }
        ss += s[i];
    }
    st.insert(ss);
    a.push_back(ss);
    int n =st.size();
    // for(auto i : st){
    //     // vis[++n] = i;
    //     cout<<i<<endl;
    // }
     int ans = 0,k = 0;
    for(int i = 0;i < n; i++){
        f[i] = 1;
        for(int j = 0;j < i ;j++){
            if(a[j] < a[i]){
                if(f[j] + 1> f[i]){
                    // cout<<a[j] <<" "<<a[i]<<endl;
                    // cout<<a[i]<<endl;
                    la[i] = j;
                    f[i] = f[j] + 1;
                    if(ans < f[i]){
                        ans = f[i];
                        k  =i;
                    }
                }
            }
            // cout<<f[j]<<" ";

        } 
        // cout<<endl;
    }
    // cout<<ans<<" "<<k<<endl;
    for (int i = 0;i < ans; ++i)
    {
        fans.push(a[k]);
        k = la[k];
    }
    while (!fans.empty())
    {
        cout<<fans.top();
        fans.pop();
    }
    cout<<endl;
    // cout<<ans[n-1]<<endl;
    return 0;
}