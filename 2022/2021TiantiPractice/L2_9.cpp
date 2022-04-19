#include <bits/stdc++.h>
using namespace std;
unordered_map<int, queue<char>> g;
stack<int> st;
vector<char> ans;

int main() 
{
    std::ios::sync_with_stdio(false);
    int n, m, s, t;
    string str;
    cin>>n>>m>>s;
    for(int i = 1; i <= n; i++) {
        cin>>str; 
        for(auto c:str)
            g[i].push(c);
    }
    while(cin>>t && t != -1){
        if(t == 0 && st.size() != 0) {
            ans.push_back(st.top());
            st.pop();
        }
        if(t == 0) continue;

        if(g[t].size() != 0) {
            char c = g[t].front();
            if(st.size() == s)  {
                ans.push_back(st.top());
                st.pop();
            }
            g[t].pop();
            st.push(c);
        }
    }
    for(auto v :ans)
        cout<<v;
    cout<<endl;
    return 0;
}