#include <bits/stdc++.h>
using namespace std;
map<char, int> vis;
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (auto ch2 : s2) {
        vis[ch2] = 1;
    }
    string ans = "";
    for (auto ch1 : s1) {
        if (vis[ch1] != 1)
            ans += ch1;
    }
    cout << ans << endl;
    return 0;
}