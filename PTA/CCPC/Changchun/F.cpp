// TODO: Time limit exceeded on test 19
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

constexpr int maxm = 2e6 + 7;

int gh[maxn], gn[maxn], gv[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int sz[maxn], son[maxn];

void dfs(int u, int fa) {
  sz[u] = 1;
  grep(i, u) {
    int v = gv[i];
    if (v != fa) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[son[u]] < sz[v]) son[u] = v;
    }
  }
}

LL a[maxn];

int check[maxm][2];

LL calc(int u, int fa, int lca, int bit) {
  LL ans = (u & bit) ? check[a[u] ^ lca][0] : check[a[u] ^ lca][1];
  grep(i, u) {
    int v = gv[i];
    if (v != fa) ans += calc(v, u, lca, bit);
  }
  return ans;
}

void join(int u, int fa, int bit) {
  (u & bit) ? ++check[a[u]][1] : ++check[a[u]][0];
  grep(i, u) {
    int v = gv[i];
    if (v != fa) join(v, u, bit);
  }
}

void dfs_clear(int u, int fa) {
  check[a[u]][0] = check[a[u]][1] = 0;
  grep(i, u) {
    int v = gv[i];
    if (v != fa) dfs_clear(v, u);
  }
}

LL solve(int u, int fa, int op, int bit) {
  LL ans = 0;
  grep(i, u) {
    int v = gv[i];
    if (v == fa || v == son[u]) continue;
    ans += solve(v, u, 0, bit);
  }
  if (son[u]) ans += solve(son[u], u, 1, bit);
  grep(i, u) {
    int v = gv[i];
    if (v == fa || v == son[u]) continue;
    ans += calc(v, u, a[u], bit);
    join(v, u, bit);
  }
  (u & bit) ? ++check[a[u]][1] : ++check[a[u]][0];
  if (!op) dfs_clear(u, fa);
  return ans;
}

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}

int main() {
  int n;
  // scanf("%d", &n);
  n = read();
  rep(i, 1, n + 1) a[i] = read();  // scanf("%lld", &a[i]);
  total = 0;
  mem(gh, -1);
  rep(i, 1, n) {
    int u, v;
    // scanf("%d%d", &u, &v);
    u = read();
    v = read();
    add(u, v);
    add(v, u);
  }
  dfs(1, 1);
  LL ans = 0;
  rep(i, 0, 17) ans += solve(1, 1, 0, 1 << i) << i;
  printf("%lld\n", ans);
}
