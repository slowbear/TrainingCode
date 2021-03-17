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

constexpr int maxn = 1010;

int a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, u, v;
    scanf("%d%d%d", &n, &u, &v);
    rep(i, 0, n) scanf("%d", &a[i]);
    int ans = min(u, v) + v;
    rep(i, 1, n) {
      if (abs(a[i] - a[i - 1]) > 1) {
        ans = min(ans, 0);
      } else if (a[i] != a[i - 1]) {
        ans = min({ans, u, v});
      }
    }
    printf("%d\n", ans);
  }
}
