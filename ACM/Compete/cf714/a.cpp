#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
int a[105];

int main()
{
    int t,k,n;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>k;
        if(k > (n -1) /2)
            cout<<-1<<endl;
        else{
            for(int i = 1;i <= k; i++)
                a[i * 2] = n + 1-i;
            int cnt = 1;
            for(int i = 1;i <= n;++i){
                if(a[i] == 0)
                {
                    cout<<cnt<<" ";
                    cnt++; 
                }
                else cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}