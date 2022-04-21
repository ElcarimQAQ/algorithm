#include <bits/stdc++.h>
using namespace std;

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string str,word;
    int cnt = 0;
    getline(cin,str);
    while(n--) {
        getline(cin,str);
        stringstream ss;
        // cout<<str<<endl;
        ss << str;
        bool flag = true;
        while (ss >> word)
        {
            if(word.find("qiandao")!= word.npos || word.find("easy")!= word.npos) {
                flag = false;
                break;
            }
        }
        if(cnt == m && flag) {
            cout<<str<<endl;
            return 0;
        }
        if(flag) cnt++;
    }
    cout<<"Wo AK le"<<endl;
    return 0;
}