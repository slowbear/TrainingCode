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

constexpr int maxn = 107;

LL a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    LL n, k;
    scanf("%lld%lld", &n, &k);
    rep(i, 0, n) scanf("%lld", &a[i]);
    LL origin = a[0], cur = a[0] * k;
    rep(i, 1, n) {
      if (a[i] * 100 > cur) {
        LL delta = (a[i] * 100 - cur + k - 1) / k;
        a[0] += delta;
        cur += delta * k;
      }
      cur += a[i] * k;
    }
    printf("%lld\n", a[0] - origin);
  }
}
