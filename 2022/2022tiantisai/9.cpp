#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
stack<int> st;
int a[maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,k,u,l;
    cin>>n>>m>>k;
    vector<int> ans;
    for(int i = 0;i < n; i++)
        cin>>a[i];
    int cnt = 0;
    while(cnt <= n ) {
        l = ans.size();
        if(st.empty() && l == 0){
            ans.push_back(a[cnt++]);
            continue;
        }
        if(st.empty()){
            if(a[cnt] < ans[l - 1])
                ans.push_back(a[cnt]);     
            else
                st.push(a[cnt]);
            cnt++;
        }else {
            int t = st.top();
            if(st.top() < ans[l - 1]) {
                ans.push_back(t);
                st.pop();
            } else{
                if(a[cnt] <= ans[l - 1]) {
                    ans.push_back(a[cnt]);
                    cnt++;
                } // 推送器上取到的松针仍然不满足要求
                else{
                    if(st.size() < m)
                    { 
                        st.push(a[cnt]);
                        cnt++;
                    } else {
                        for(int i =0;i <ans.size();i++){
                            if(i == ans.size() - 1)
                                cout<<ans[i]<<endl;
                            else cout<<ans[i]<<" ";
                        }
                        ans.clear();
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
            }
        }
        if(ans.size() == k) {  //手中的松枝干上已经插满了松针
             for(int i =0;i <ans.size();i++){
                if(i == ans.size() - 1)
                    cout<<ans[i]<<endl;
                else cout<<ans[i]<<" ";
            }
            ans.clear();
        }
    }
    // cout<<ans.size()<<endl;
    for(int i =0;i <ans.size();i++){
        if(ans[i] == 0){
            cout<<endl;
            break;
        }
        if(i == 0)
            cout<<ans[i];
        else cout<<" "<<ans[i];
    }
    
    
    return 0;
}