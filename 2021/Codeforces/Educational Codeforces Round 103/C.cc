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

constexpr int maxn = 2e5 + 7;

LL a[maxn], b[maxn], c[maxn];

LL f[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &c[i]);
    rep(i, 0, n) scanf("%lld", &a[i]);
    rep(i, 0, n) scanf("%lld", &b[i]);
    rep(i, 0, n) if (a[i] > b[i]) swap(a[i], b[i]);
    f[0] = 0;
    LL ans = 0;
    rep(i, 1, n) {
      if (a[i] == b[i]) {
        f[i] = c[i] + 1;
      } else {
        f[i] = (c[i] + 1) + max(b[i] - a[i], f[i - 1] + a[i] - b[i]);
      }
      if (f[i] > ans) ans = f[i];
    }
    printf("%lld\n", ans);
  }
}
