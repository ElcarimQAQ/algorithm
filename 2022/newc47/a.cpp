#include <bits/stdc++.h>
using namespace std;
const double PI =  3.141592653589;


int main() 
{
    int t,r,h;
    cin>>t;
    while(t--) {
        cin>>r>>h;
        int cnt = h / (2 * r);
        double ans = PI*r*r*h - PI*r*r*r* 4.0/3.0*cnt;
        printf("%.3lf\n", ans);
    }
    return 0;
}