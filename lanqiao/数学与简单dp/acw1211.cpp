#include<bits/stdc++.h>
using namespace std;
const int maxn  = 55;
int a[maxn];

int main()
{
    int n,m;
    cin>>n;
    int vis = 0;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n; i++){
        cin>>a[i];
        if(i == 1) 
            vis = fabs(a[i]);
        else{
            if(a[1] < 0){
                if(fabs(a[i]) < vis && a[i] > 0)
                    cnt1++;
                if(fabs(a[i]) > vis && a[i] < 0)
                    cnt2++;
            }
            if(a[1] > 0){
                if(fabs(a[i]) > vis && a[i] < 0)
                    cnt1++;
                if(fabs(a[i]) < vis && a[i] > 0)
                    cnt2++;
            }
        }
    }
    int ans= 1;
    if(cnt1 == 0) ans =1;
    else{
        ans += cnt1 + cnt2;
    }
    cout<<ans<<endl;
    
    return 0;
}