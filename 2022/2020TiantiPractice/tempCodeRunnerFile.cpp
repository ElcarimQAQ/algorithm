#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int cnt = 0,first,num = 0;
    while(getline(cin, str)) {
        if(str == ".") break;
        num++;
        if(str.find("chi1 huo3 guo1") != str.npos){
            if(cnt == 0) first = num;
            cnt++;
        }
    }
    cout<<num<<endl;
    if(cnt == 0 ) cout<<"-_-#"<<endl;
    else cout<<first<<' '<<cnt<<endl;
    return 0;
}