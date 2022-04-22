
#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    int ans = 5000 - 50 * (100 - x + y) ;
    cout<<ans<<endl;
    return 0;
}