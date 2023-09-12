#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y, depth;
    Point(int x, int y) : x(x), y(y), depth(0) {}
};

// 计算向量 AB 和向量 AC 的叉积
int cross_product(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// 计算向量 AB 与 x 轴正方向的夹角（弧度）
double polar_angle(const Point& A, const Point& B) {
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    return atan2(dy, dx);
}

vector<Point> compute_convex_hull(vector<Point>& points) {
    // 找到 y 坐标最小的点
    Point p0 = *min_element(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
    });

    // 将其他点按照极角排序
    sort(points.begin(), points.end(), [&](const Point& p1, const Point& p2) {
        double angle1 = polar_angle(p0, p1);
        double angle2 = polar_angle(p0, p2);
        return angle1 < angle2 || (angle1 == angle2 && (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) <
                                                  (p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y));
    });

    // 计算凸包
    vector<Point> hull;
    for (int i = 0; i < points.size(); i++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        if (hull.empty() || points[i].x != hull.back().x || points[i].y != hull.back().y) {
            hull.push_back(points[i]);
            hull.back().depth = hull.size() - 1;
        }
    }

    // 将凸包上的点深度设为 0
    for (Point& p : hull) {
        p.depth = 0;
    }

    return hull;
}

vector<int> compute_depth(vector<Point>& points) {
    vector<Point> hull = compute_convex_hull(points);
    vector<int> depths(points.size());
    for (int i = 0; i < points.size(); i++) {
        depths[i] = points[i].depth;
    }
    return depths;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
    vector<int> depths = compute_depth(points);
    for (int depth : depths) {
        cout << depth << endl;
    }
    return 0;
}