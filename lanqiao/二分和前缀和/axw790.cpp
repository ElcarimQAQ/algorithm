#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
const  int maxn = 100005;
int a[maxn];
double n;
int check(double m){
    if( m * m * m <= n)
        return 1;
    return 0;
}
int main()
{
    cin>>n;
    double l = -10000.0,r = 10000.0;
    while (l + eps < r)
    {
        double m = (l + r) /2.0;
        if(check(m)) l = m  ;
        else r = m;
    }
    printf("%.6lf",l);
    return 0;

}