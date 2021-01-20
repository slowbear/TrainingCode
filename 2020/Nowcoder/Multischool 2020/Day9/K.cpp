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

constexpr int maxn = 401000;

int gh[maxn], gv[maxn], gn[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int parent[maxn], down[maxn], up[maxn];

bool vis[maxn];

void calc(int u, int fa) {
  vis[u] = true;
  parent[u] = fa;
  down[u] = 0;
  up[u] = up[fa] + 1;
  grep(i, u) {
    int v = gv[i];
    if (!vis[v]) {
      calc(v, u);
      if (down[v] + 1 > down[u]) down[u] = down[v] + 1;
    }
  }
}

int main() {
  int n, t;
  freopen("input.in", "r", stdin);
  scanf("%d%d", &n, &t);
  total = 0;
  mem(gh, -1);
  mem(gn, -1);
  mem(vis, 0);
  rep(i, 1, n) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  up[n] = -1;
  calc(n, n);
  int cur = 1;
  rep(i, 0, t) cur = parent[cur];
  int cur_dist = up[cur], step = up[cur] / 3;
  int ans = down[cur] >= cur_dist ? cur_dist : (down[cur] + cur_dist + 1) / 2;
  rep(i, 0, step) {
    cur = parent[cur];
    cur_dist -= 3;
    int tmp = down[cur] >= cur_dist ? cur_dist : (down[cur] + cur_dist + 1) / 2;
    tmp += i + 1;
    if (tmp > ans) ans = tmp;
  }
  printf("%d\n", ans);
}
