#include<bits/stdc++.h>
using namespace std;
unordered_map<int ,int > pre;

int find(int a)
{
    if(pre[a] == 0)
        return a;
    else
        return pre[a] = find(pre[a]);
    
}

void Union(int a,int b){
    int m = find(a);
    int n = find(b);
    pre[m] = n;
    return ;
}

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        pre.clear();
        int flag = 1;
        int n,a,b,c;
        cin >> n;
        for(int i = 0 ;i < n; i++) {
            cin>>a>>b>>c;
            int m = find(a);
            int n = find(b);
            if(c == 1 ){
                if( m!=n && a !=m &&b != n){
                    flag = 0;
                    break;
                }
                else 
                    Union(a,b);
            }
            else{
                if( m == n){
                    flag = 0;
                    break;
                }      
            }
        }
        if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    system("pause");
    return 0;
}