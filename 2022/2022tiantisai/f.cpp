#include <bits/stdc++.h>
using namespace std;
int a[6];
int vis[10][6];
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string ans1,ans2,a;
    ans1 = "";
    a = s1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
            ans1 += max(a[i], a[i-1]);
        }
    }
    a = s2;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
            ans2 += max(a[i], a[i-1]);
        }
    }
    if(ans1 == ans2)cout<<ans1<<endl;
    else {
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    }

    return 0;
}