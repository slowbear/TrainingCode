#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define SZ(V) (int)(V.size())
#define mp make_pair
constexpr int maxn = 101000;

VI g[maxn];
Pii p[maxn];
int fa[maxn];
bool done[maxn];

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

void join(int u, int v) { fa[find_fa(u)] = find_fa(v); }

bool connect(int u, int v) { return find_fa(u) == find_fa(v); }

bool Compare(const Pii& x, const Pii& y) {
  if (x.second == y.second) return x.first > y.first;
  return x.second > y.second;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, n + 1) {
      fa[i] = i;
      g[i].clear();
    }
    rep(i, 0, n) {
      p[i].first = i + 1;
      scanf("%d", &p[i].second);
    }
    rep(i, 0, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    sort(p, p + n, Compare);
    mem(done, 0);
    LL ans = 0;
    rep(i, 0, n) {
      int u = p[i].first, cnt = 0;
      for (int v : g[u]) {
        if (!done[v]) continue;
        if (!connect(u, v)) {
          join(u, v);
          ++cnt;
        }
      }
      ans -= 1LL * (cnt - 1) * p[i].second;
      done[u] = true;
    }
    printf("%lld\n", ans);
  }
}
