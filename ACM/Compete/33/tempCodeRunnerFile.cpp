#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
typedef pair<int ,int> PII;
const  int maxn = 5e5+5;
ll a[maxn],l[maxn];
int n,k;
inline double sqr(double x){
    return x*x;
}

int cmp(double x){
    if(fabs(x) < eps) return 0;
    if(x > 0) return 1;
    return -1;
}

struct point {
    double x,y;
    point (){}
    point(double a,double b):x(a),y(b){}
    friend point operator + (const point &a,const point &b){
        return point(a.x + b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x - b.x,a.y - b.y);
    }
    friend point operator * (const double &a,const point &b){
        return point(a * b.x,a * b.y);
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x * b,a.y * b);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x / b,a.y / b);
    }
    double norm(){
        return sqrt(sqr(x) + sqr(y));
    }
};

struct line{
    point a,b;
    line(){}
    line(point x,point y): a(x),b(y) {}
};


double det(const point &a,const point &b){
        return a.x * b.y - a.y * b.x;
}

double dot(const point &a,const point &b){
        return a.x * b.x + a.y * b.y;
}

double dist(const point &a,const point &b){
    return (a - b).norm();
}

line point_make_line(const point a,const point b){
    return line(a,b);
}

void PointProLine(const point p,const point s,const point t,point &cp ){
    double r = dot(t - s,p -s) / dot(t-s,t -s);
    cp = s + r * (t - s);
}

bool par(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}

bool line_make_point(line a,line b,point &res){
    if(par(a,b))
        return false;
    double s1 =det(a.a - b.a,b.b - b.a);
    double s2 = det(a.b - b.a ,b.b-b.a);
    res = (s1*a.b - s2*a.a) /(s1 -s2);
    return true;
}

int main()
{
    double x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    point a(x1,y1);
    point b(x2,y2);
    line l1 =point_make_line(a,b);
    cin>>x1>>y1;
    cin>>x2>>y2;
    point c(x1,y1);
    point d(x2,y2);
    line l2 =point_make_line(c,d);
    point e;
    if(!line_make_point(l1,l2,e))cout<<0<<endl;
    else{
        double dis = dist(a,b);
        point cp1,cp2;
        PointProLine(c,a,b,cp1);
        PointProLine(d,a,b,cp2);
        double cx1 = dist(c,cp1),cx2 = dist(d,cp2);
        double ans = dis * (cx1+cx2) /2.0;
        printf("%.7lf\n",ans);
    }
    return 0;
}