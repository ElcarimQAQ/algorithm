#include <bits/stdc++.h>
using namespace std;
int dp[30];
vector<int> ans;
int main(){

    int n,b,k = 0;
    cin>>n>>b;
    if(n == 0) {
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        return 0;
    }
    while(n > 0) {
        ans.push_back(n % b);
        n = n / b;
        k++;
    }
    bool falg = true;
    reverse(ans.begin(), ans.end());
    for(int i = 0;i < k / 2; i++) {
        if(ans[i] != ans[k - 1 - i]) {
            cout<<"No"<<endl;
            falg = false;
            break;
        }
    }
    if(falg) 
        cout<<"Yes"<<endl;
    for(auto v : ans) 
        cout<<v<<" ";
    
    return 0;
}