#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int ans = 1;
    for(int i = 2;i <= 20; ++i){
        ans += 4 * (i - 1);
    }
    cout<<ans;
    return 0;
}