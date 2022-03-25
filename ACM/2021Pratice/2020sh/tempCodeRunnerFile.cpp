#include<bits/stdc++.h>
using namespace std;
double n,p1,v1,p2,v2,p3;
string s1[1005],s2[1005];
double ans;
double slove(double l,double r)
{
    for(int i = 0; i < 100 ; i++){
        double m = (l + r) / 2.0;
        double ll = min((2.0 * m + p1) / v1,(m + 2 * p1) / v1);
        double rr = min(2.0 * (p2 - m) + p3 / v2,(p2 - m + 2 * p3) / v2);
        ans = min(ans,max(ll,rr));
        if(ll < rr)
            l = m;
        else
            r = m;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>p1>>v1>>p2>>v2;
        if(p1 > p3){
            swap(p1,p3);
            swap(v1,v2);
        }
        p2 = p3 - p1;
        double t1 = max((n - p1) / v1,p2 / v2);
        double t2 = min((n + p3) / v2,(n + p1) / v1);
        ans = min(t1,t2);
        double t3 = slove(p1,p3);
        printf("%.10lf\n",ans);
    }
    return 0;
}