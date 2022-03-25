#include <bits/stdc++.h>
using namespace std;
int a[105];
 
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int cnt = 0;
        memset(a,0,sizeof(a));
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            if(i > 1 && (a[i] != a[i - 1] )){
                if(a[i] == a[i - 2] || i <= 2)
                    cnt = i - 1;
                else
                    cnt = i ;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}