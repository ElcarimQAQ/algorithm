#include <bits/stdc++.h>
using namespace std;
unordered_set<int> h,l;
int main()
{
    int n,m,q,t,c;
    cin>>n>>m>>q;
    int ans = 0;
    while(q--) {
        cin>>t>>c;
        if(t) {
            if(h.count(c) == 0 && c <= n){
                h.insert(c);
            }
        }else {
            if(l.count(c) == 0 && c<= m){
                l.insert(c);
            }
        }
    }
    ans = h.size() * m + l.size() * n -  h.size() * l.size();
    cout<<n * m -ans<<endl;
    return 0;
}