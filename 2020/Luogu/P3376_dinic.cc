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
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxm = 2e4 + 7;

constexpr int maxn = 300;

int gh[maxn], gv[maxm], gn[maxm], total;

LL cap[maxm];

void init() {
  mem(gh, -1);
  total = 0;
}

void add(int u, int v, int c) {
  gv[total] = v;
  cap[total] = c;
  gn[total] = gh[u];
  gh[u] = total++;
  gv[total] = u;
  cap[total] = 0;
  gn[total] = gh[v];
  gh[v] = total++;
}

int cur[maxn], d[maxn];

bool bfs(int s, int t) {
  mem(d, -1);
  d[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    grep(i, u) {
      int v = gv[i];
      if (!cap[i] || d[v] != -1) continue;
      d[v] = d[u] + 1;
      que.push(v);
    }
  }
  return d[t] != -1;
}

LL dinic(int u, int t, LL rest) {
  if (!rest || (u == t)) return rest;
  LL total = 0;
  gcur(i, u) {
    int v = gv[i];
    if (!cap[i] || d[v] != d[u] + 1) continue;
    int flow = dinic(v, t, min(rest, cap[i]));
    rest -= flow;
    cap[i] -= flow;
    cap[i ^ 1] += flow;
    total += flow;
    if (!rest) break;
    cur[u] = i;
  }
  return total;
}

LL maxflow(int s, int t) {
  LL flow = 0;
  while (bfs(s, t)) {
    copy(gh, gh + maxn, cur);
    flow += dinic(s, t, INT32_MAX);
  }
  return flow;
}

int main() {
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  init();
  while (m--) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    add(u, v, c);
  }
  printf("%lld\n", maxflow(s, t));
}
