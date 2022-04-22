#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1005;

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    while(k--) {
        stack<int> st;
        int ne = 1;
        int vis[maxn] = {0};
        int u;
        bool flag = true;
        for(int i = 0; i <n ;i++) {
            cin>>u;
            if(!flag) continue;
            vis[u] = 1;
            if(ne == u) ne++;
            else if(!vis[ne]) {
                st.push(u);
                if(st.size() > m) {  //超出容量限制
                    flag = false;
                }
            } 
            //出现过
            while(vis[ne]) {
                if(st.top() != ne){ 
                    flag = false;
                    break;
                } else {
                    ne++;
                    st.pop();
                }
            }
            
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}