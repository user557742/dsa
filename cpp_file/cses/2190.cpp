// CSES 2190 - Line Segment Intersection
// Uses orientation (cross product) + on-segment checks.
// Handles large coordinates safely using __int128 for cross products.

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

inline __int128 cross128(const Point &a, const Point &b, const Point &c) {
    // cross of (b - a) x (c - a)
    return (__int128)(b.x - a.x) * (__int128)(c.y - a.y)
         - (__int128)(b.y - a.y) * (__int128)(c.x - a.x);
}

int sign128(__int128 v) {
    if (v == 0) return 0;
    return v > 0 ? 1 : -1;
}

bool onSegment(const Point &a, const Point &b, const Point &p) {
    // check if p lies on segment ab (assuming collinear)
    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x)
         && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}

bool segmentsIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    __int128 c1 = cross128(a, b, c);
    __int128 c2 = cross128(a, b, d);
    __int128 c3 = cross128(c, d, a);
    __int128 c4 = cross128(c, d, b);

    int s1 = sign128(c1);
    int s2 = sign128(c2);
    int s3 = sign128(c3);
    int s4 = sign128(c4);

    // General case: orientations differ
    if (s1 * s2 < 0 && s3 * s4 < 0) return true;

    // Special cases: collinear and overlapping / touching
    if (s1 == 0 && onSegment(a, b, c)) return true;
    if (s2 == 0 && onSegment(a, b, d)) return true;
    if (s3 == 0 && onSegment(c, d, a)) return true;
    if (s4 == 0 && onSegment(c, d, b)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
    Point a, b, c, d;
    if (!(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y)) return 0;

    cout << (segmentsIntersect(a, b, c, d) ? "YES\n" : "NO\n");
    return 0;
    }
}
