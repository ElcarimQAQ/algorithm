#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

bool check(int x)
{
    if(x - 1 >= 0 && s[x - 1] == s[x])
        return false;
    if(x + 1 < s.length() && s[x + 1] == s[x])
        return false;
    return true;
}

int main ()
{

    cin>>s;
    int cnt = 0;
    int f  = 0,la = -5;
    for(int i = 0; i < s.length(); ++i){
        if(check(i) && f == 0)
            f = 1;
        if(s[i] == '1'){
            if(i - la == 1 ){
                la = i;
                continue;
            }
            cnt++;
            la = i;
        }
    }
    if(f)
        cout<<cnt - 1<<endl;
    else
        cout<<cnt <<endl;
    
    return 0;
}
