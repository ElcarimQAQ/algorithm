#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main()
{
    int n,k,h;
    cin>>h>>n>>k;
    int e[maxn],ne[maxn],pre[maxn];
    int ad,data, next;
    while(n--) {
        cin>>ad>>data>>next;
        e[ad] = data;
        ne[ad] = next;
        pre[next] = ad;
    }
    int end;
    int cnt = 0;
    vector<int> st,ans;
    for(int i = h; i != -1;i = ne[i]) {
        end = i;
        if(cnt == k){
            for(int i = st.size() -1; i>=0;i--)
            {
                int a = st[i];
                ans.push_back(a);
            }
            cnt = 0;
            st.clear();
        }
        st.push_back(i);
        cnt++;
    }
    if(cnt < k) { //bug1,最后也可能小于k，要判断
        for(int i = 0; i<st.size(); i++) {
            int a = st[i];
            ans.push_back(a);
        }
    }else {
        for(int i = st.size() -1; i>=0;i--) {
            int a = st[i];
            ans.push_back(a);
        }
    }
    for(int i=0;i < ans.size() - 1; i++)
        printf("%05d %d %05d\n",ans[i],e[ans[i]],ans[i+1]);
    printf("%05d %d -1\n",ans[ans.size() - 1],e[ans[ans.size() - 1]]);
    return 0;
}
