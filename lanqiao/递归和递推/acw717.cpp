#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50];
int main()
{
    int n;
    cin>>n;
    f[1] = 0;
    f[2] = 1;
    for(int i = 3;i <= n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    for(int i =1; i <= n; ++i)
        cout<<f[i]<<" ";
    cout<<endl;
    return 0;
}