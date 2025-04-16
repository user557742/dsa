#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
typedef pair<double, double> p2d;

const double EPS = 1e-8;

double cross(p2d a, p2d b) {
    return a.x * b.y - a.y * b.x;
}

double dot(p2d a, p2d b) {
    return a.x * b.x + a.y * b.y;
}

bool ol(p2d a, p2d b, p2d c) {
    p2d ac = {c.x - a.x, c.y - a.y};
    p2d bc = {c.x - b.x, c.y - b.y};
    return fabs(cross(ac, bc)) < EPS && dot(ac, bc) <= EPS;
}

p2d timgiao(p2d a, p2d b, p2d u, p2d v) {
    p2d ab = {b.x - a.x, b.y - a.y};
    p2d uv = {v.x - u.x, v.y - u.y};
    p2d au = {u.x - a.x, u.y - a.y};
    double goc = cross(ab, uv);
    if (fabs(goc) < EPS) return mp(1e12, 1e12);
    double t = cross(au, uv) / goc;
    double s = cross(au, ab) / goc;
    if (t < -EPS || t > 1 + EPS || s < -EPS || s > 1 + EPS)
        return mp(1e12, 1e12);
    return mp(a.x + ab.x * t, a.y + ab.y * t);
}

p2d gdt(p2d a, p2d b, p2d u, p2d v) {
    p2d x = timgiao(a, b, u, v);
    if (ol(a, b, x) && ol(u, v, x)) return x;
    return mp(1e12, 1e12);
}

bool ccw(p2d a, p2d b, p2d c) {
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y) > EPS;
}

p2d mvec(p2d u, p2d v) {
    return mp(v.x - u.x, v.y - u.y);
}

bool check(p2d u, p2d a, p2d b, p2d c) {
    p2d ua = mvec(u, a), ub = mvec(u, b), uc = mvec(u, c);
    p2d ab = mvec(a, b), ac = mvec(a, c);
    double Sabc = 0.5 * fabs(cross(ab, ac));
    double Suab = 0.5 * fabs(cross(ua, ub));
    double Subc = 0.5 * fabs(cross(ub, uc));
    double Suca = 0.5 * fabs(cross(uc, ua));
    return fabs(Suab + Subc + Suca - Sabc) < EPS;
}

int main() {
    p2d a1, b1, c1, a2, b2, c2;
    cin >> a1.x >> a1.y >> b1.x >> b1.y >> c1.x >> c1.y;
    cin >> a2.x >> a2.y >> b2.x >> b2.y >> c2.x >> c2.y;

    vector<p2d> cgd;

    auto add_if_valid = [&](p2d p) {
        if (p.x != 1e12 || p.y != 1e12)
            cgd.push_back(p);
    };

    add_if_valid(gdt(a1, b1, a2, b2));
    add_if_valid(gdt(a1, b1, b2, c2));
    add_if_valid(gdt(a1, b1, c2, a2));
    add_if_valid(gdt(b1, c1, a2, b2));
    add_if_valid(gdt(b1, c1, b2, c2));
    add_if_valid(gdt(b1, c1, c2, a2));
    add_if_valid(gdt(c1, a1, a2, b2));
    add_if_valid(gdt(c1, a1, b2, c2));
    add_if_valid(gdt(c1, a1, c2, a2));

    if (check(a1, a2, b2, c2)) cgd.push_back(a1);
    if (check(b1, a2, b2, c2)) cgd.push_back(b1);
    if (check(c1, a2, b2, c2)) cgd.push_back(c1);
    if (check(a2, a1, b1, c1)) cgd.push_back(a2);
    if (check(b2, a1, b1, c1)) cgd.push_back(b2);
    if (check(c2, a1, b1, c1)) cgd.push_back(c2);
    sort(cgd.begin(), cgd.end());
    cgd.erase(unique(cgd.begin(), cgd.end(), [](p2d a, p2d b) {
        return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
    }), cgd.end());

    if (cgd.empty()) {
        cout << "0.00";
        return 0;
    }
    sort(cgd.begin(), cgd.end());
    vector<p2d> ch;
    for (auto& p : cgd) {
        while (ch.size() >= 2 && !ccw(ch[ch.size()-2], ch.back(), p))
            ch.pop_back();
        ch.push_back(p);
    }
    int t = ch.size();
    for (int i = cgd.size() - 2; i >= 0; --i) {
        while ((int)ch.size() > t && !ccw(ch[ch.size()-2], ch.back(), cgd[i]))
            ch.pop_back();
        ch.push_back(cgd[i]);
    }
    if (ch.size() > 1) ch.pop_back();
    double S = 0;
    for (int i = 1; i + 1 < (int)ch.size(); ++i) {
        p2d u = {ch[i].x - ch[0].x, ch[i].y - ch[0].y};
        p2d v = {ch[i+1].x - ch[0].x, ch[i+1].y - ch[0].y};
        S += 0.5 * fabs(cross(u, v));
    }

    cout << fixed << setprecision(2) << S;
    return 0;
}
