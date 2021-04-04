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

constexpr int maxn = 610;

int color[maxn];

bool vis[maxn];

VP g;

int main() {
  int n, m, colors;
  scanf("%d%d%d", &n, &m, &colors);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    g.pb(mp(u, v));
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int cnt = 0;
    mem(vis, 0);
    rep(i, 1, n + 1) {
      scanf("%d", &color[i]);
      if (!vis[color[i]]) {
        vis[color[i]] = true;
        ++cnt;
      }
    }
    bool flag = (cnt == colors);
    for (auto i : g) {
      if (color[i.first] == color[i.second]) flag = false;
    }
    printf(flag ? "Yes\n" : "No\n");
  }
}
