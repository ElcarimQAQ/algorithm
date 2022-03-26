#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,f;
    cin>>a>>b;
    int ans = a+b;
    string s = "";
    string num = to_string(ans);
    for(int i = num.size() - 1,j = 0; i >= 0; i--){
        ++j;
        s = num[i] + s;
        if(j % 3 == 0 && i != 0 && num[i-1]!= '-' ){
            s = ","+s;
        }
    }
    cout<<s<<endl;
}
