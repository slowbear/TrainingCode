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

constexpr int maxn = 101000;

LL a[maxn], l[maxn], r[maxn], rest[maxn];

int main() {
  LL k, L, R;
  scanf("%lld%lld%lld", &k, &L, &R);
  rep(i, 0, k) scanf("%lld", &a[i]);
  rep(i, 0, k) scanf("%lld%lld", &l[i], &r[i]);
  LL x = 0, y = 1e9 + 7;
  while (x + 1 < y) {
    LL mid = (x + y) / 2;
    LL cur = 0;
    bool flag = true;
    rep(i, 0, k) {
      rest[i] = a[i] - mid * l[i];
      if (rest[i] < 0) {
        flag = false;
        break;
      }
      cur += mid * l[i];
    }
    if (cur > mid * R) flag = false;
    if (!flag) {
      y = mid;
      continue;
    }
    rep(i, 0, k) cur += min(rest[i], mid * (r[i] - l[i]));
    if (cur >= mid * L)
      x = mid;
    else
      y = mid;
  }
  printf("%lld\n", x);
}
