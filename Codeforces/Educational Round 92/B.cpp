#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (int)(V.size())

constexpr int maxn = 101000;

int a[maxn], p[maxn], prefix[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k, z;
    scanf("%d%d%d", &n, &k, &z);
    rep(i, 0, n) scanf("%d", &a[i]);
    prefix[0] = a[0];
    rep(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
    rep(i, 1, n) p[i] = a[i] + a[i - 1];
    rep(i, 2, n) p[i] = max(p[i], p[i - 1]);
    int ans = prefix[k];
    rep(use, 1, z + 1) {
      // int cur = prefix[k - use];
      // if (use & 1) cur += a[k - use - 1];
      // cur += p[k - use] * (use >> 1);
      // ans = max(ans, cur);
      int cur;
      if (k > 2 * use) {
        cur = prefix[k - 2 * use] + p[k - 2 * use] * use;
        ans = max(ans, cur);
      }
      if (k >= 2 * use) {
        cur = prefix[k - 2 * use + 1] + a[k - 2 * use] + p[k - 2 * use + 1] * (use - 1);
        ans = max(ans, cur);
      }
    }
    printf("%d\n", ans);
  }
}