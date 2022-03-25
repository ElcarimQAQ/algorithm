#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
int mo[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int n[4];

int run(int y){
    if(y % 100 == 0 && y % 400 == 0)
        return 1;
    if(y % 100 != 0 && y % 4 == 0)
        return 0;
    return 1;
}

string change(int x)
{
    string s="";
    while(x > 0){
        int p =x % 10;
        s += (p +'0');
        x /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    // int s;
    string s,ans1 = "",ans2 = "";
    cin>>s;
    int m = (s[4] - '0') * 10 + s[5] - '0';
    int d = (s[6] - '0') * 10 + s[7] - '0';
    int y = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
    
    int yy,mm,dd;
    for(int i = y; ; i++){
        string s1 = "",s2 = "";
        mo[1] = 28;
        s1 = change(i);
        mm = (s1[3] - '0') * 10 + s1[2] - '0';
        dd = (s1[1] - '0') * 10 + s1[0] - '0';
        if(run(i)) mo[1] = 29;
        // cout<<i<<endl;
        // cout<<mm<<" "<<dd<<endl;
        if(mm > 12 || mm <= 0 || dd > mo[mm - 1] || dd <= 0 )
            continue;
        if(y == i && ( mm < m || (mm == m && dd <= d)))
            continue;
        s2 += s1;
        reverse(s1.begin(),s1.end());
        s2 +=  s1;
        if(s2[0] == s2[2] && s2[1] == s2[3] && s2[0] != s2[1]){
            ans2 += s2;
            if(ans1 == "") ans1 += s2;
            cout<<ans1<<endl;
            cout<<ans2<<endl;
            break;
        }
        else{
            if(ans1 == "") ans1 += s2;
        }
    }
    return 0;
}