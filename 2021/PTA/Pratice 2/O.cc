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

constexpr int maxn = 5010;

Pii p[maxn];

Pii operator-(Pii a, Pii b) { return {a.first - b.first, a.second - b.second}; }

double calc(Pii a, Pii b) { return a.second * b.first - a.first * b.second; }

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d%d", &p[i].first, &p[i].second);
  double ans = 1e18;
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
    double tmp = abs(calc(p[j] - p[i], p[k] - p[i])) / 2.0;
    if (tmp < ans) ans = tmp;
  }
  printf("%.3f\n", ans);
}
