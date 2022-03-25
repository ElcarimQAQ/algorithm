#include<bits/stdc++.h>
using namespace std;
string s;
#define INF 1e6

int check(int x){
    string s2= "ocha";
    for(int i = 0; i < 4; i++){
        if(s2[i] != s[x + i + 1])
            return 0;
    }
    return 1;
}

vector<int> pos;
int main()
{
    int n,k;
    cin>>n>>k;
    cin>>s;
    for(int i = 0;i < s.size(); i++){
        if(s[i] == 'm'){
            if(check(i)){
                pos.push_back(i);
            }
        }
    }
    if(k > pos.size()){
        cout<<"poor Mocha"<<endl;
        return 0;
    }
    int ans = INF;
    for(int i = 0;i < pos.size();i++){
        int j = i + k - 1;
        if(j >= pos.size())
            break;
        ans = min(ans,pos[j] - pos[i] + 5);
    }
    cout<<"Mocha suki!"<<endl;
    cout<<ans<<endl;
    return 0;
}