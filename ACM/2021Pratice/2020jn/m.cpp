#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ans;
    cin>>n>>k;
    if(n < k)
        ans = 2;
    else{
        if(n * 2 % k == 0)
        {
            ans = n * 2 / k;
        }
        else
            ans = n * 2 / k +1;
    }
    cout<<ans<<endl;
    return 0;
}