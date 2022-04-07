#include <bits/stdc++.h>
using namespace std;
map<string, int> vis;

int check (int c) {
    if( c >= 'a' && c <= 'z')
        return 1;
    if( c >= '0' && c <= '9')
        return 1;
    return 0;
}

int main()
{
    string str, word = "";
    getline(cin, str);
    int ma = 0;
    for (auto ch : str) {
        ch = tolower(ch);
        if( check(ch) ){
            word += ch;
        } else {
            if(word != ""){
                vis[word]++;
                ma = max(ma,vis[word]);
            }
            word = "";
        }
    }
    if(word != ""){
        vis[word]++;
        ma = max(ma,vis[word]);
    }
    for (auto i : vis){
        if(i.second == ma){
            cout<<i.first<<" " << i.second<<endl;
            break;
        }
    }
    return 0;
}