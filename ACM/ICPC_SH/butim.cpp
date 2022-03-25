#include<bits/stdc++.h>
using namespace std;
#define seed 131
int T;
double n,p1,v1,p2,v2;
double x1,x2,x3;
double t1,t2,t3;
vector<int>t[105];
map<string ,int> mp;


void dfs(int u,int fa)
{

}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>> n>> m;
        string s,ss;
        stringstream str;
        int k= 0;
        for(int i = 1;i<= n;i++){
            cin>>s;
            s =s +'/';
            for(int j = 0 ; j < s.size(); j++){
                if(s[j] == '/'){
                    s[j] = ' ';
                    //cout<<s<<endl;
                }
            }
            str<<s;
            while(str>>ss){
                cout<<ss<<endl;
            }
        }
    }
    system("pause");
    return 0;
}