#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 10;
typedef long long ll;
ll a[maxn];
int vis[maxn];

int slove(){
    int f = 0;
    for(int i = 1;i <= 6; i++){
        for(int j = i+1;j <= 6;j++){
            for(int m = j+1;m <= 6;m++){
                if(a[i] + a[j] > a[m] ){
                    vis[i] = vis[j] = vis[m] = 1;
                    int cnt = 0;
                    ll sum = 0;
                    for(int k = 1;k <= 6;k++){
                        if(vis[k] == 0 ){
                            cnt++;
                            if(cnt == 3){
                                if(sum > a[k]){
                                    f = 1;
                                    return 1;
                                }
                            }
                            else
                                sum += a[k];
                        }
                    }
                }
                vis[m] = 0;
            }
            vis[j] = 0;
        }
        vis[i] = 0;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        for(int i = 1;i <= 6;i++)
            cin>>a[i];
        sort(a + 1,a + 1 + 6);
        if(slove() == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}