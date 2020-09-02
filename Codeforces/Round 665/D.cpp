#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 2e5 + 7;

constexpr int p = 1e9 + 7;

int gh[maxn], gv[maxn], gn[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

LL sz[maxn];

void dfs(int u, int fa) {
  sz[u] = 1;
  grep(i, u) {
    int v = gv[i];
    if (v != fa) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

VLL w;

void calc(int u, int fa) {
  grep(i, u) {
    int v = gv[i];
    if (v != fa) {
      w.pb(sz[v] * (sz[1] - sz[v]));
      calc(v, u);
    }
  }
}

LL fac[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    total = 0;
    mem(gh, -1);
    rep(i, 1, n) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    dfs(1, 1);
    w.clear();
    calc(1, 1);
    sort(w.begin(), w.end());
    int m, last = SZ(w);
    scanf("%d", &m);
    rep(i, 0, m) scanf("%lld", &fac[i]);
    while (m < last) fac[m++] = 1;
    sort(fac, fac + m);
    LL ans = 0;
    if (m > last) rep(i, last, m) fac[last - 1] = fac[last - 1] * fac[i] % p;
    rep(i, 0, last) ans = (ans + w[i] * fac[i] % p) % p;
    printf("%lld\n", ans % p);
  }
}
