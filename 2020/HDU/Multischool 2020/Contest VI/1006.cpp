#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 501000;

constexpr int p = 1e9 + 7;

int a[maxn], fa[maxn], u[maxn], v[maxn];

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

void join(int u, int v) { fa[find_fa(v)] = find_fa(u); }

bool within(int u, int v) { return find_fa(u) == find_fa(v); }

int gh[maxn], gv[maxn], gn[maxn], gw[maxn], total;

void add(int u, int v, int w) {
  gv[total] = v;
  gw[total] = w;
  gn[total] = gh[u];
  gh[u] = total++;
}

int sz[maxn][2];

void get_size(int u, int fa) {
  sz[u][0] = sz[u][1] = 0;
  ++sz[u][a[u]];
  grep(i, u) {
    int v = gv[i];
    if (v != fa) {
      get_size(v, u);
      sz[u][0] += sz[v][0];
      sz[u][1] += sz[v][1];
    }
  }
}

LL calc(int u, int fa, int c0, int c1) {
  LL ans = 0;
  grep(i, u) {
    int v = gv[i];
    if (v != fa) {
      LL cur = (sz[v][0] * (c1 - sz[v][1]) + sz[v][1] * (c0 - sz[v][0])) % p;
      cur = cur * gw[i] % p;
      ans = (ans + calc(v, u, c0, c1) + cur) % p;
    }
  }
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    total = 0;
    rep(i, 1, n + 1) {
      scanf("%d", &a[i]);
      fa[i] = i;
      gh[i] = -1;
    }
    int cur = 1;
    rep(i, 0, m) {
      cur = (cur << 1) % p;
      scanf("%d%d", &u[i], &v[i]);
      if (!within(u[i], v[i])) {
        add(u[i], v[i], cur);
        add(v[i], u[i], cur);
        join(u[i], v[i]);
      }
    }
    get_size(1, 1);
    printf("%lld\n", calc(1, 1, sz[1][0], sz[1][1]));
  }
}
