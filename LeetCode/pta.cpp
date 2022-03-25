#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<double,double>a,b,c;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    double pa,pb,pc;
    double p = a.first * a.second + b.first * b.second + c.first * c.second;
    pa = a.first * a.second / p;
    pb = b.first * b.second / p;
    pc = c.first * c.second / p;
    printf("%.3lf %.3lf %.3lf\n",pa,pb,pc);
    int ans = 0;
    if(pa == max(pa,max(pb,pc)))
        ans = 1;
    if(pb == max(pa,max(pb,pc)))
        ans = 2;
    if(pc == max(pa,max(pb,pc)))
        ans = 3;
    cout<<ans<<endl;
    return 0;
}