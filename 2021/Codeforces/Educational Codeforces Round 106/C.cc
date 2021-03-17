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

constexpr int maxn = 2e5 + 7;

LL a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &a[i]);
    LL ans = a[0] * n + a[1] * n, sum = ans;
    LL cur[2] = {a[0], a[1]};
    rep(i, 2, n) {
      sum += a[i] - cur[i & 1];
      if (a[i] < cur[i & 1]) {
        sum += (a[i] - cur[i & 1]) * (n - i / 2 - 1);
        cur[i & 1] = a[i];
      }
      if (sum < ans) ans = sum;
    }
    printf("%lld\n", ans);
  }
}
