#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define SZ(V) (int)(V.size())
#define mp make_pair
constexpr int p = 1e9 + 7;
constexpr int maxn = 101000;

Pll a[maxn];

int fa[maxn];

LL cnt[2];

LL C(LL n, LL k) {
  LL ans = 1;
  if (n < k) return 0;
  rep(i, 1, k + 1) ans = ans * (n - i + 1) / i;
  return ans;
}

LL ans[maxn];

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

void join(int u, int v) {
  u = find_fa(u);
  v = find_fa(v);
  a[u].first += a[v].first;
  a[u].second += a[v].second;
  fa[v] = u;
}

LL calc(int u, int v) {
  return (a[u].first * a[v].second + a[v].first * a[u].second) *
             (cnt[0] - a[u].second - a[v].second) +
         (a[u].second * a[v].second) *
             ((cnt[0] - a[u].second - a[v].second) + (cnt[1] - a[u].first - a[v].first));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    mem(cnt, 0);
    rep(i, 1, n + 1) {
      int flag;
      fa[i] = i;
      scanf("%d", &flag);
      if (flag & 1)
        a[i] = mp(1LL, 0LL);
      else
        a[i] = mp(0LL, 1LL);
      ++cnt[flag & 1];
    }
    ans[0] = C(cnt[0], 3) + C(cnt[0], 2) * cnt[1];
    rep(i, 1, n) {
      int u, v;
      scanf("%d%d", &u, &v);
      ans[i] = ans[i - 1] - calc(find_fa(u), find_fa(v));
      join(u, v);
    }
    rep(i, 0, n) printf("%lld\n", ans[i] % p);
  }
}
