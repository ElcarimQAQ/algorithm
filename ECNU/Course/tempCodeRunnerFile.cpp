#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct Point {
    int x, y;
};
vector<Point> points;
Point p0 ;
int depths[N];

// 计算两点之间的距离的平方
int distSq(Point p1, Point p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

// 计算向量之间的点积
int dotProduct(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}


// 用于判断三个点是否形成一个左转方向（逆时针方向）
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // 共线
    return (val > 0) ? 1 : 2;  // 顺时针或逆时针方向
}

// 比较函数，用于排序点集P
bool comparePoints(Point p1, Point p2) {
    // 按照极角排序
    int orientationVal = orientation(p0, p1, p2);
    if (orientationVal == 0) {
        // 如果两个点共线，将距离较近的点排在前面
        return (distSq(p0, p1) <= distSq(p0, p2));
    }
    return (orientationVal == 2);
}

// 找到最低的点，如果存在多个点具有相同的y坐标，则选择最左边的点作为起点
int findLowestPoint(vector<Point>& points) {
    int lowest = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < points[lowest].y ||
            (points[i].y == points[lowest].y && points[i].x < points[lowest].x)) {
            lowest = i;
        }
    }
    return lowest;
}
// 计算向量之间的叉积
int crossProduct(Point p1, Point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

// 计算凸包，并返回凸包上的点集
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};  // 点集P中的点数小于3，无法构成凸包

    // 找到起始点
    int lowest = findLowestPoint(points);
    swap(points[0], points[lowest]);

    // 按照极角排序
    sort(points.begin() + 1, points.end(), comparePoints);

    // 构建凸包
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    int depth = 0;
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2){
            hull.pop_back();
            depth++;
        }
        hull.push_back(points[i]);
        depths[i] = depth;
    }

    return hull;
}

// 计算点集 P 中所有点的深度
void findDepths(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return;  // 点集P中的点数小于3，无法构成凸包

    // 计算凸包
    vector<Point> hull = convexHull(points);
    // 输出点集 P 中所有点的深度
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for(auto j :hull) {
            if(j.x == points[i].x && j.y == points[i].y)
                flag = true;
        }
        if (flag)cout << "Depth of point (" << points[i].x << ", " << points[i].y << "): " << depths[i] << endl;
        else cout << "Depth of point (" << points[i].x << ", " << points[i].y << "): " << 0 << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >>y;
        points.push_back({x, y});
    }

    findDepths(points);
    return 0;
}