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

constexpr int maxn = 307;

LL g[maxn][maxn];

int path[maxn];

int check[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    LL w;
    scanf("%d%d%lld", &u, &v, &w);
    g[u][v] = g[v][u] = w;
  }
  int T;
  scanf("%d", &T);
  LL ans = -1;
  while (T--) {
    int k;
    scanf("%d", &k);
    if (k != n) {
      while (k--) scanf("%*d");
      continue;
    }
    rep(i, 1, n + 1) check[i] = 0;
    rep(i, 1, k + 1) {
      scanf("%d", &path[i]);
      check[path[i]] = 1;
    }
    int vis = 0;
    rep(i, 1, n + 1) vis += check[i];
    if (vis != n) continue;
    path[0] = path[k + 1] = 0;
    LL sum = 0;
    rep(i, 1, k + 2) {
      if (!g[path[i - 1]][path[i]]) {
        sum = -1;
        break;
      }
      sum += g[path[i - 1]][path[i]];
    }
    if ((sum != -1) && (ans == -1 || sum < ans)) ans = sum;
  }
  printf("%lld\n", ans);
}
