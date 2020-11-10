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

int n, m, k;

constexpr int maxn = 1e6 + 7;

int gh[maxn], cur[maxn], gv[maxn], gn[maxn], cap[maxn], total;

void add(int u, int v, int c) {
  gv[total] = v;
  cap[total] = c;
  gn[total] = gh[u];
  gh[u] = total++;
  ////
  gv[total] = u;
  cap[total] = 0;
  gn[total] = gh[v];
  gh[v] = total++;
}

int d[maxn];

bool bfs(int s, int t) {
  mem(d, -1);
  queue<int> que;
  que.push(s);
  d[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    grep(i, u) {
      if (!cap[i]) continue;
      int v = gv[i];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        que.push(v);
      }
    }
  }
  return d[t] != -1;
}

int dinic(int u, int t, int rest) {
  if (!rest || (u == t)) {
    return rest;
  }
  int sum = 0;
  gcur(i, u) {
    int v = gv[i];
    if (cap[i] && (d[v] == d[u] + 1)) {
      int f = dinic(v, t, min(rest, cap[i]));
      rest -= f;
      sum += f;
      cap[i] -= f;
      cap[i ^ 1] += f;
      if (!rest) break;
    }
    cur[u] = i;
  }
  return sum;
}

int solve(int s, int t) {
  int ans = 0;
  while (bfs(s, t)) {
    copy(gh, gh + n + m + 3, cur);
    ans += dinic(s, t, 1e9);
  }
  return ans;
}

int main() {
  mem(gh, -1);
  total = 0;
  scanf("%d%d%d", &n, &m, &k);
  rep(i, 1, n + 1) {
    add(0, i + 1, 1);
    add(1, i + 1, 1);
    int t;
    scanf("%d", &t);
    while (t--) {
      int j;
      scanf("%d", &j);
      add(i + 1, j + n + 1, 1);
    }
  }
  rep(j, 1, m + 1) add(j + n + 1, n + m + 2, 1);
  add(0, 1, k);
  int ans = solve(0, n + m + 2);
  printf("%d\n", ans);
}
