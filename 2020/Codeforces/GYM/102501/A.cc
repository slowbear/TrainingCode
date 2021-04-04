#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pii = pair<int, int>;
using VI = vector<int>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 1010;

inline int sqr(int x) { return x * x; }

inline int distance(Pii x, Pii y) {
  return ceil(sqrt(sqr(x.first - y.first) + sqr(x.second - y.second)));
}

int c[maxn];

Pii p[maxn];

vector<Pii> e[maxn];

LL f[110][maxn];

int main() {
  Pii s, t;
  scanf("%d%d", &s.first, &s.second);
  scanf("%d%d", &t.first, &t.second);
  int B;
  scanf("%d", &B);
  scanf("%d", &c[0]);
  int T;
  scanf("%d", &T);
  rep(i, 1, T + 1) scanf("%d", &c[i]);
  int n;
  scanf("%d", &n);
  rep(i, 0, n) {
    scanf("%d%d", &p[i].first, &p[i].second);
    int links;
    scanf("%d", &links);
    while (links--) {
      int station, mode;
      scanf("%d%d", &station, &mode);
      e[i].pb(mp(station, mode));
      e[station].pb(mp(i, mode));
    }
  }
  p[n] = s;
  p[n + 1] = t;
  e[n].pb(mp(n + 1, 0));
  e[n + 1].pb(mp(n, 0));
  rep(i, 0, n) {
    e[n].pb(mp(i, 0));
    e[n + 1].pb(mp(i, 0));
    e[i].pb(mp(n, 0));
    e[i].pb(mp(n + 1, 0));
  }
  mem(f, 0x3f);
  f[0][n] = 0;
  rep(lim, 1, B + 1) {
    f[lim][n] = 0;
    rep(u, 0, n + 2) {
      for (auto link : e[u]) {
        int v = link.first, m = link.second, dis = distance(p[u], p[v]);
        if (lim >= dis) f[lim][v] = min(f[lim][v], f[lim - dis][u] + 1LL * c[m] * dis);
      }
    }
  }
  printf("%lld\n", f[B][n + 1] == f[0][n + 1] ? -1LL : f[B][n + 1]);
}
