#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans = 1;
    for(int i = a+b ;i >=1;i--)
        ans *=i;
    cout<<ans<<endl;
    return 0;
}