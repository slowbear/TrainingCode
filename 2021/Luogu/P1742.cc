#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 1e5 + 7;

constexpr double eps = 1e-7;

struct Point {
  double x, y;
  Point operator+(const Point &other) const { return {x + other.x, y + other.y}; }
  Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
  Point operator*(double factor) const { return {x * factor, y * factor}; }
  Point operator/(double factor) const { return {x / factor, y / factor}; }
  Point rotate() const { return {-y, x}; }
  double operator*(const Point &other) const { return x * other.x + y * other.y; }
  double operator^(const Point &other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(*this * *this); }
};

double rsin(const Point &p1, const Point &p2) { return (p1 ^ p2) / p1.length() / p2.length(); }

Point cross(const Point &u1, const Point &v1, const Point &u2, const Point &v2) {
  Point a = v1 - u1, b = v2 - u2, u = v1 - v2;
  return v1 - a * (u ^ b) / (a ^ b);
}

struct Circle {
  Point o;
  double r;
  bool include(const Point &p) const { return (p - o).length() <= r + eps; }
};

Circle generate_circle(const Point &x, const Point &y, const Point &z) {
  Point a = y - x, b = z - y, m1 = (x + y) / 2, m2 = (y + z) / 2;
  Point o = cross(m1, m1 + a.rotate(), m2, m2 + b.rotate());
  double r = (z - x).length() / fabs(rsin(a, b)) / 2;
  return {o, r};
}

Point p[maxn];

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%lf %lf", &p[i].x, &p[i].y);
  shuffle(p, p + n, mt19937(random_device{}()));
  Circle ans = {{0, 0}, 0};
  rep(i, 0, n) {
    if (ans.include(p[i])) continue;
    ans = {p[i], 0};
    rep(j, 0, i) {
      if (ans.include(p[j])) continue;
      ans = {(p[i] + p[j]) / 2, (p[i] - p[j]).length() / 2};
      rep(k, 0, j) {
        if (ans.include(p[k])) continue;
        ans = generate_circle(p[i], p[j], p[k]);
      }
    };
  }
  printf("%.10f\n", ans.r);
  printf("%.10f %.10f\n", ans.o.x, ans.o.y);
}
