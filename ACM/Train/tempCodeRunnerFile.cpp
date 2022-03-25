#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
#define down 0.99

int n;
double ansx,ansy,answ;
struct node {
    int xi,yi,wi;
}a[maxn];

double cal(double x,double y)
{
    double ans = 0.0,dx,dy;
    for(int i = 1;i <= n;++i){
        dx = x - a[i].xi;
        dy = y - a[i].yi;
        ans += sqrt(dx * dx + dy * dy) * a[i].wi;
    }
    return ans;
}

void sa()
{
    double t =3000;
    while(t > 1e-14)
    {
        double ex = ansx + (rand() * 2 - RAND_MAX ) * t;
        double ey = ansy + (rand() * 2 - RAND_MAX ) * t;
        double ew = cal(ex,ey);
        double de = ew -answ;
        if(ew - answ < 0){
            ansx = ex;
            ansy = ey;
            answ = ew;
        }
        else if(exp(-de / t) * RAND_MAX > rand()){
            ansx = ex;
            ansy = ey;
        }
        t *= down;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n; i++){
        scanf("%d%d%d",&a[i].xi,&a[i].yi,&a[i].wi);
        ansx += a[i].xi;
        ansy += a[i].yi;
    }
    ansx /= n;
    ansy /= n;
    answ = cal(ansx,ansy);
    sa();
    printf("%.3lf %.3lf\n",ansx,ansy);
    return 0;
}