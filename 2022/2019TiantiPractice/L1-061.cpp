
#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    double w,h;
    cin>>w>>h;
    double ans = w / (h * h);
    printf("%.1lf\n",ans);
    if(ans > 25)puts("PANG");
    else puts("Hai Xing");
    return 0;
}