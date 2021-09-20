#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

struct user{
    string id,p;
};

vector<user> ans;

char rep(char c){
    if(c == '1')
        return '@';
    if(c == '0')
        return '%';
    if(c == 'l')
        return 'L';
    if(c == 'O')
        return 'o';
    return c;
}

int main()
{
    int n;
    cin>>n;
    int m = 0;
    for (int i = 1;i <=n;i++)
    {
        user u;
        cin>>u.id>>u.p;
        int f = 0;
        for(int j =0;j < u.p.size();j++){
            char c = rep(u.p[j]);
            if(c!= u.p[j] ){
                u.p[j] = c;
                f = 1;
            }
        }
        if(f) {
            m++;
            ans.push_back(u);
        }
        
    }
    if(m == 0){
        if(n == 1)
            printf("There is %d account and no account is modified\n",n);
        else 
            printf("There are %d accounts and no account is modified\n",n);
    }
    else{
        cout<<m<<endl;
        for(auto v : ans){
            cout<<v.id<<" "<<v.p<<endl;
        }

    }
    
    return 0;
}