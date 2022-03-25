#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

const double eps = 1e-15;

struct point {

    double x,y,len2,angle;

    point() {}

    point(double _x,double _y){

        set(_x,_y);

    }

    point operator-(const point& p) {

        return point(x - p.x, y - p.y);

    }

    double operator^(const point& p) {

        return x * p.y - y * p.x;

    }

    void set(double _x,double _y){

        x =_x,y =_y;

        len2 = x * x + y * y;

        angle  =atan2(y,x);

    }

    bool operator ==(const point& p) {

        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;

    }

    double length() { return sqrt(len2); }

} p[maxn];

vector<point> vis[maxn];

struct line{

    point st,ed,vec;

    double len2,angle;

    line() {}

    line(point s, point e) { set(s, e); }

    void set(point s,point e){

        st = s, ed = e, vec = e - s;

        len2 = vec.len2;

        angle = atan2(vec.y,vec.x);

    }

    bool on_line(point p) {

        return fabs(vec ^ (p - st)) < eps;

    }

    bool on_segment(point p) {

        if (p.x + eps < min(st.x, ed.x) || p.x - eps > max(st.x, ed.x))

            return false;

        if (p.y + eps < min(st.y, ed.y) || p.y - eps > max(st.y, ed.y))

            return false;

        return on_line(p);

    }

    point get_inter(line l){

        double x1 = st.x,y1 = st.y,x2 = ed.x,y2 = ed.y;

        double x3 = l.st.x,y3 = l.st.y ,x4 = l.ed.x,y4 = l.ed.y;

        double k1 = (x4 - x3) * (y2 - y1),k2 = (x2 - x1)*(y4- y3);

        double x = (k1 * x1 - k2 *x3 + (y3-y1) *(x2 - x1) *(x4 - x3))/(k1 - k2);

        double y = (k2*y1 - k1 * y3 + (x3 - x1) *(y2 - y1)*(y4 - y3))/(k2- k1);

        return point(x,y);

    }

    bool parallel(line l) {

        return fabs(vec ^ l.vec) < eps;

    }

};

point s,e;

bool cmp(point a, point b) {

    a = a - s;

    a.len2 = a.x * a.x + a.y * a.y;

    b = b - s;

    b.len2 = b.x * b.x + b.y * b.y;

    return a.len2 < b.len2;

}

int main()

{

    int n,m;

    scanf("%d%d", &n, &m);

    scanf("%lf%lf%lf%lf", &s.x, &s.y, &e.x, &e.y);

    line l; l.set(s,e);

    for(int i = 1;i <= n;++i){

        scanf("%lf%lf", &p[i].x, &p[i].y);

    }

    for(int i = 1;i <= n;++i){

        for(int j = 1;j <= n; ++j) if (i != j) {

            line no; no.set(p[i],p[j]);

            //if (no.parallel(l)) continue;

            point q = no.get_inter(l);

            //cout << i << ' ' << j << ' ' << q.x << ' ' << q.y << endl;

            if (l.on_segment(q)) {

                vis[i].push_back(q);

            }

        }

    }

    for (int i = 1; i <= n; ++i) {

        sort(vis[i].begin(), vis[i].end(), cmp);

    }

    int k,h;

    while(m--){

        scanf("%d%d", &h, &k);

        if (k > vis[h].size()) printf("-1\n");

        else{ 
            if(vis[h][k -1].y == -0.0000)
                printf("%.8lf %.8lf\n", vis[h][k - 1].x, 0.0);
            else if(vis[h][k -1].x == -0.0000)
                printf("%.8lf %.8lf\n", 0.0, vis[h][k - 1].y);
            else
                printf("%.8lf %.8lf\n", vis[h][k - 1].x, vis[h][k - 1].y);
        }
    }

}