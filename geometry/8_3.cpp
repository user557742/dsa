#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i)
        for (int j = i + 1; j < right; ++j)
            minDist = min(minDist, distance(points[i], points[j]));
    return minDist;
}

double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j)
            minDist = min(minDist, distance(strip[i], strip[j]));
    return minDist;
}

double closestUtil(vector<Point>& points, int left, int right) {
    if (right - left <= 3)
        return bruteForce(points, left, right);

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; ++i)
        if (abs(points[i].x - midPoint.x) < d)
            strip.push_back(points[i]);

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size());
}

int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << fixed << setprecision(6) << "Khoảng cách gần nhất: " << closestPair(points) << endl;
    return 0;
}
