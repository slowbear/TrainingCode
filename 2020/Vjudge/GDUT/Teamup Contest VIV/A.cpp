// TODO: This solution is wrong but accepted. Waitting to rewrite.
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

constexpr int maxn = 3000;

constexpr int maxm = 4001000;

struct Graph {
  int gh[maxn], gv[maxm], gn[maxm], total;
  Graph() : total(0) { mem(gh, -1); }
  void add(int u, int v) {
    gv[total] = v;
    gn[total] = gh[u];
    gh[u] = total++;
  }
} p, q;

int dis[maxn], n;

bool bfs(int s, const Graph &g) {
  queue<int> que;
  VI cleanup;
  que.push(s);
  dis[s] = 0;
  cleanup.pb(s);
  while (!que.empty()) {
    int u = que.front();
    for (int i = g.gh[u]; i != -1; i = g.gn[i]) {
      int v = g.gv[i];
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        cleanup.pb(v);
        if (dis[v] > 1) return false;
        que.push(v);
      }
    }
    que.pop();
  }
  for (int u : cleanup) dis[u] = -1;
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    rep(i, 0, n) rep(j, 0, n) {
      char ch;
      scanf(" %c", &ch);
      if (ch == 'P') p.add(i, j);
      if (ch == 'Q') q.add(i, j);
    }
    bool flag = true;
    mem(dis, -1);
    rep(i, 0, n) {
      flag = bfs(i, p) && bfs(i, q);
      if (!flag) break;
    }
    puts(flag ? "T" : "N");
  }
}
