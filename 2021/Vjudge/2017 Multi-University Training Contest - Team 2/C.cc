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

constexpr int maxn = 5e5 + 7, p = 1e9 + 7;

LL a[maxn], b[maxn];

LL f[maxn];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    rep(i, 1, n + 1) scanf("%lld", &a[i]);
    rep(i, 1, n + 1) scanf("%lld", &b[i]);
    f[n] = a[n] - n;
    rev(i, 1, n) f[i] = max(a[i] - i, f[i + 1]);
    sort(b + 1, b + n + 1);
    LL cur = f[n], sum = 0;
    rep(i, n + 1, 2 * n + 1) {
      a[i] = max(f[b[i - n]], cur);
      f[i] = a[i] - i;
      sum = (sum + a[i]) % p;
      cur = max(cur, f[i]);
    }
    printf("%lld\n", sum);
  }
}
