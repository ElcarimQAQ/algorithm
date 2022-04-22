
#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    string str;
    getline(cin, str);
    string ans = "";
    // cout<<str;
    int cnt = 0;
    for(int i = 0;i < str.size(); i++) {
        if(str[i] == '6')
            cnt++;
        if(str[i] != '6' || i == str.size() - 1) {
            if(cnt > 3 && cnt <= 9 ) ans += "9";
            else if(cnt > 9) ans += "27";
            else if(cnt != 0){
                while(cnt--) ans += '6';
            }
            if(i == str.size() - 1 && cnt != 0){
                break;
            }
            ans += str[i];
            cnt = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}