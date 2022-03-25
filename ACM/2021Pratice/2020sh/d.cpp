#include<bits/stdc++.h>
using namespace std;
double n,p1,v1,p2,v2,p3;
double ans;

double cal(double x,double p,double v){
    return min(x + p,x + x - p) / v;
}
double slove(double l,double r)
{
    for(int i = 0; i < 100 ; i++){
        double m = (l + r) / 2.0;
        double ll = cal(m,p1,v1);
        double rr = cal(n - m,p2 - m,v2);
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
        if(p1 > p2){
            swap(p1,p2);
            swap(v1,v2);
        }
        double t1 = min(cal(n,p1,v1),cal(n,p2,v2));
        double t2 = max((n - p1) / v1,p2 / v2);
        ans = min(t1,t2);
        double t3 = slove(p1,p2);
        printf("%.10lf\n",ans);
    }
    return 0;
}