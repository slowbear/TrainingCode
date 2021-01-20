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

constexpr int maxn = 101000;

int cnt[maxn];

map<Pii, int> e;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    e.clear();
    rep(i, 1, n + 1) cnt[i] = 0;
    rep(i, 1, n) {
      int u, v, val;
      scanf("%d%d%d", &u, &v, &val);
      if (u > v) swap(u, v);
      e[mp(u, v)] = val;
      cnt[u] += val;
      cnt[v] += val;
    }
    while (m--) {
      int ord;
      scanf("%d", &ord);
      if (ord) {
        int u, v, val;
        scanf("%d%d%d", &u, &v, &val);
        if (u > v) swap(u, v);
        int dx = val - e[mp(u, v)];
        cnt[u] += dx;
        cnt[v] += dx;
        e[mp(u, v)] = val;
      } else {
        int u;
        scanf("%d", &u);
        puts(cnt[u] & 1 ? "Girls win!" : "Boys win!");
      }
    }
  }
}
