// #include <bits/extc++.h>
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

constexpr int maxn = 1010;

set<pair<double, double>> f;

pair<double, double> p[maxn];

inline pair<double, double> operator-(pair<double, double> a, pair<double, double> b) {
  return {a.first - b.first, a.second - b.second};
}

inline pair<double, double> operator+(pair<double, double> a, pair<double, double> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<double, double> rotate(pair<double, double> d, bool flag) {
  return flag ? make_pair(-d.second, d.first) : make_pair(d.second, -d.first);
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    f.clear();
    int ans = 0;
    rep(i, 0, n) {
      scanf("%lf%lf", &p[i].first, &p[i].second);
      f.insert(p[i]);
    }
    rep(i, 0, n) rep(j, i + 1, n) {
      auto d = p[i] - p[j];
      if (f.count(p[j] + rotate(d, false)) && f.count(p[i] + rotate(d, false))) ++ans;
      if (f.count(p[j] + rotate(d, true)) && f.count(p[i] + rotate(d, true))) ++ans;
    }
    printf("%d\n", ans / 4);
  }
}
