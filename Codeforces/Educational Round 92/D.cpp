#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
using Pll = pair<LL, LL>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define SZ(V) (int)(V.size())

inline bool cross(Pll x, Pll y) {
  return x.first <= y.first ? x.second >= y.first : y.second >= x.first;
}

inline Pll join(Pll x, Pll y) { return mp(min(x.first, y.first), max(x.second, y.second)); }

inline Pll both(Pll x, Pll y) { return mp(max(x.first, y.first), min(x.second, y.second)); }

inline LL length(Pll l) { return l.second - l.first; }

inline LL rest(Pll x, Pll y) { return length(join(x, y)) * 2 - length(x) - length(y); }

inline LL gap(Pll x, Pll y) { return max(x.first, y.first) - min(x.second, y.second); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    Pll a, b;
    scanf("%lld%lld", &a.first, &a.second);
    scanf("%lld%lld", &b.first, &b.second);
    if (cross(a, b)) {
      LL cur = length(both(a, b)) * n, ans = 0;
      if (cur >= k) {
        printf("0\n");
        continue;
      }
      k -= cur;
      cur = rest(a, b) * n;
      if (k <= cur) {
        printf("%lld\n", k);
        continue;
      }
      ans += cur;
      k -= cur;
      ans += 2 * k;
      printf("%lld\n", ans);
    } else {
      LL g = gap(a, b), r = length(join(a, b)), cur = 0, cost = 0;
      bool used = false;
      while (cur < k) {
        if (used && ((n == 0) || (2 * (k - cur) <= min(k - cur, r) + g))) {
          cost += 2 * (k - cur);
          cur = k;
        } else {
          cost += g;
          LL delta = min(k - cur, r);
          cost += delta;
          cur += delta;
          --n;
          used = true;
        }
      }
      printf("%lld\n", cost);
    }
  }
}