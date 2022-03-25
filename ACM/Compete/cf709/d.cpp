#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
#define  PII pair<int,int>
deque<PII > q;
vector<int> ans;
PII pos[maxn];

int gcd(int a,int b){
    return b == 0 ? a:gcd(b,a % b);
}


int main()
{
    ios::sync_with_stdio(false);
    int t,n,a,cnt;
    PII x1,x2;
    cin>>t;
    while(t--){
        cnt  = 0;
        q.clear();
        ans.clear();
        cin>>n;
        for(int i = 1;i <= n; i++){
            cin>>a;
            q.push_back({a,i});
        }
        while(!q.empty()){
            x1 = q.front();
            q.pop_front();
            if(q.size() == 0)
                x2 = x1;
            else x2 = q.front();
            // cout<<x1.first<<" "<<x2.first<<endl; 
            if(gcd(x1.first,x2.first) != 1)
                cnt++;
            else{
                cnt = 0;
                ans.push_back(x2.second);
                if(q.size() != 0)q.pop_front();
            }
            if(cnt > q.size() || q.size() == 0)
                break;
            q.push_back(x1);
        }
        cout<<ans.size()<<" ";
        for(auto i : ans)
            cout<<i <<" ";
        cout<<endl;
    }

    return 0;
}