#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n;
    vector<pair<int,int > > ans;
    m = n;
    
    if(n == 1) {
        cout<<"1=1";
        return 0;
    }
    int cnt = 0;
    for(int i = 2 ;i <= sqrt(m); i++) {
        if( n % i == 0) {
            ans.push_back({i, 0});
            while(n % i ==0)  {
                n /= i;
                ans[cnt].second++;
            }
            cnt++;
        }
    }
    if(n != 1) {
        ans.push_back({n,1});
        cnt++;
    }
    cout<<m<<"=";
    for(int i = 0 ;i <cnt;i++) {
        auto v = ans[i];
        if(i == 0 ){
            if(v.second == 1 ) cout<<v.first;
            else cout<<v.first<<'^'<<v.second;
        }
        else {
            if(v.second == 1 ) cout<<'*'<<v.first;
            else cout<<'*'<<v.first<<'^'<<v.second;
        }
    }

    
    return 0;
}