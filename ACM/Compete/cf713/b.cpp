#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
 
int main()
{
    int t,n;
    string s[maxn];
    cin>>t;
    while(t--){
        cin>>n;
        pair<int,int> a,b;
        int cnt = 0;
        for(int i =0;i < n; ++i)
            cin>>s[i];
        for(int i = 0;i < n; ++i){
            for(int j =0;j < n; ++j){
                if(s[i][j] == '*'){
                    if(!cnt)
                        {a={i,j};cnt = 1;}
                    else b= {i,j};
                }
            }
        }
        if(a.first == b.first){
            if(a.first != n-1){
                s[a.first + 1][a.second] = '*';
                s[b.first + 1][b.second] = '*';
            }
            else{
                s[a.first - 1][a.second] = '*';
                s[b.first - 1][b.second] = '*';
            }
        }
        else if(a.second == b.second){
            if(a.second != n-1){
                s[a.first][a.second + 1] = '*';
                s[b.first][b.second + 1] = '*';
            }
            else{
                // cout<<"?"<<endl;
                s[a.first ][a.second - 1] = '*';
                s[b.first ][b.second - 1] = '*';
            }
        }
        else{
            s[a.first][b.second] = '*';
            s[b.first][a.second] = '*';
        }
        for(int i =0; i < n; ++i)
            cout<<s[i]<<endl;
        
    }
    return 0;
}