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

pair<double, double> a[maxn];

bool compare(const Pii &x, const Pii &y) { return x.second * y.first > x.first * y.second; }

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  rep(i, 0, n) scanf("%lf", &a[i].first);
  rep(i, 0, n) scanf("%lf", &a[i].second);
  sort(a, a + n, compare);
  double ans = 0;
  rep(i, 0, n) {
    if (d >= a[i].first) {
      ans += a[i].second;
      d -= a[i].first;
    } else {
      ans += 1.0 * a[i].second / a[i].first * d;
      break;
    }
  }
  printf("%.2f\n", ans);
}
