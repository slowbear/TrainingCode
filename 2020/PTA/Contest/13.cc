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

constexpr int maxn = 10400000;

int fa[maxn], vis[maxn], sz[maxn];

int n, m, l, t;

inline int get_id(int x, int y, int z) { return z * n * m + x * m + y; }

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

bool is_union(int x, int y) { return find_fa(x) == find_fa(y); }

void join(int u, int v) {
  u = find_fa(u);
  v = find_fa(v);
  if (u != v) {
    fa[v] = u;
    sz[u] += sz[v];
  }
}

int main() {
  // freopen("input.in", "r", stdin);
  scanf("%d%d%d%d", &n, &m, &l, &t);
  rep(k, 0, l) rep(i, 0, n) rep(j, 0, m) {
    int id = get_id(i, j, k);
    scanf("%d", &sz[id]);
    fa[id] = id;
  }
  rep(k, 0, l) rep(i, 0, n) rep(j, 0, m) {
    int id = get_id(i, j, k), new_id;
    if (!sz[id]) continue;
    if (i + 1 < n) {
      new_id = get_id(i + 1, j, k);
      if (sz[new_id]) join(id, new_id);
    }
    if (j + 1 < m) {
      new_id = get_id(i, j + 1, k);
      if (sz[new_id]) join(id, new_id);
    }
    if (k + 1 < l) {
      new_id = get_id(i, j, k + 1);
      if (sz[new_id]) join(id, new_id);
    }
  }
  LL ans = 0;
  rep(k, 0, l) rep(i, 0, n) rep(j, 0, m) {
    int id = find_fa(get_id(i, j, k));
    if (vis[id]) continue;
    vis[id] = true;
    if (sz[id] >= t) ans += sz[id];
  }
  printf("%lld\n", ans);
}
