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

VI g[maxn];

int fa[maxn], query[maxn];

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

void join(int u, int v) { fa[find_fa(u)] = find_fa(v); }

bool is_link(int u, int v) { return find_fa(u) == find_fa(v); }

bool vis[maxn], flag[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  rep(i, 0, n) fa[i] = i;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].pb(v);
    g[v].pb(u);
  }
  int k;
  scanf("%d", &k);
  mem(vis, 0);
  rep(i, 0, k) scanf("%d", &query[i]);
  rep(i, 0, k) vis[query[i]] = true;
  rep(u, 0, n) if (!vis[u]) {
    for (int v : g[u])
      if (!vis[v]) join(u, v);
  }
  rev(i, 0, k) {
    int u = query[i];
    bool first_join = true;
    flag[i] = true;
    for (int v : g[u]) {
      if (vis[v]) continue;
      if (first_join) {
        join(u, v);
        first_join = false;
      } else {
        if (!is_link(u, v)) {
          join(u, v);
          flag[i] = false;
        }
      }
    }
    vis[u] = false;
  }
  rep(i, 0, k) {
    if (flag[i]) {
      printf("City %d is lost.\n", query[i]);
    } else {
      printf("Red Alert: City %d is lost!\n", query[i]);
    }
  }
  if (n == k) printf("Game Over.\n");
}
