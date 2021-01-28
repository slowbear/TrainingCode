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

LL a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, 2 * n) scanf("%lld", &a[i]);
    sort(a, a + 2 * n, greater<>());
    bool ans = true;
    rep(i, 0, n) {
      if (a[2 * i] != a[2 * i + 1]) {
        ans = false;
        break;
      }
    }
    rep(i, 1, n) {
      LL pre = a[2 * (i - 1)], suf = a[2 * i];
      if (pre == suf) {
        ans = false;
        break;
      }
      if ((pre - suf) % (2 * (n - i)) != 0) {
        ans = false;
        break;
      }
      LL cur = (pre - suf) / (2 * (n - i));
      a[2 * n - 1] -= 2LL * i * cur;
    }
    if (a[2 * n - 1] <= 0) ans = false;
    if (a[2 * n - 1] % (2LL * n)) ans = false;
    puts(ans ? "YES" : "NO");
  }
}
