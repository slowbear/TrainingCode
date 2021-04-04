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

int gh[maxn], gn[maxn], gv[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int outd[maxn], dep[maxn], fa[maxn];

void dfs(int u, int f, int d) {
  outd[u] = 0;
  dep[u] = d;
  fa[u] = f;
  grep(i, u) {
    int v = gv[i];
    if (v != f) {
      dfs(v, u, d + 1);
      ++outd[u];
    }
  }
}

int query[maxn], white[maxn];

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    int n, q;
    scanf("%d%d", &n, &q);
    total = 0;
    fill(gh + 1, gh + n + 1, -1);
    printf("Case #%d:\n", index);
    rep(i, 1, n) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    dfs(1, 1, 0);
    while (q--) {
      int m, ans = 0;
      scanf("%d", &m);
      rep(i, 0, m) scanf("%d", &query[i]);
      sort(query, query + m, [](int u, int v) { return dep[u] > dep[v]; });
      rep(i, 0, m) {
        int u = query[i];
        int black = outd[u] - white[u];
        if (black <= 1) {
          ++ans;
          if (!black) white[fa[u]]++;
        }
      }
      printf("%d\n", n - ans);
      rep(i, 0, m) white[fa[query[i]]] = 0;
    }
  }
}
