#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int vis[100];

void slove(string str, string str2, int n){
    if(n == str.size()) {
        ans++;
        cout<<str2<<endl;
        return;
    }
    for(int i = 0;i < str.size(); i++) {
        if(vis[i] == 1)
            continue;
        vis[i] = 1;
        slove(str, str2 + str[i], n + 1);
        vis[i] = 0;
    }
}


int main() {
    string str = "abcde";
    slove(str, "", 0);
    cout<<ans<<endl;
    return 0;
}