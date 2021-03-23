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

constexpr int maxn = 1e4 + 7, maxm = 1e5 + 7;

int gh[maxn], gn[maxm], gv[maxm], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

bitset<maxn> g[maxn];

void dfs(int u, int rt) {
  g[rt][u] = 1;
  grep(i, u) {
    int v = gv[i];
    if (!g[rt][v]) dfs(v, rt);
  }
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    mem(gh, -1);
    total = 0;
    scanf("%d%d", &n, &m);
    rep(i, 1, n + 1) g[i].reset();
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    bool flag = true;
    rep(u, 1, n + 1) dfs(u, u);
    rep(u, 1, n + 1) rep(v, u + 1, n + 1) {
      if (!g[u][v] && !g[v][u]) {
        flag = false;
        break;
      }
    }
    puts(flag ? "I love you my love and our love save us!" : "Light my fire!");
  }
}
