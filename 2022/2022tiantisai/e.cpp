#include <bits/stdc++.h>
using namespace std;
int a[6];
int vis[10][6];
int main()
{
    for(int i= 0;i < 6;i++){
        cin>>a[i];
        vis[a[i]][i] = 1;
    }
    int n;
    cin>>n;
    while(n--) {
        for(int i = 0;i < 6 ;i++){
            for(int j = 6;j >= 1;j--) {
                if(!vis[j][i]) {
                    vis[j][i] = 1;
                    a[i] = j;
                    break;
                }
            }
        }
    }
     for(int i= 0;i < 6;i++){
        if(i == 5) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }

    return 0;
}