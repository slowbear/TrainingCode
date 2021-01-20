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

constexpr int maxn = 1010;

constexpr int maxm = 201000;

int gh[maxn], gv[maxm], gn[maxm], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int color[maxn];

bool flag;

queue<int> que;

void bfs() {
  while (flag && !que.empty()) {
    int u = que.front();
    que.pop();
    grep(i, u) {
      int v = gv[i];
      if (color[u] == color[v]) {
        flag = false;
        break;
      }
      if (color[v] == -1) {
        color[v] = color[u] ^ 1;
        que.push(v);
      }
    }
  }
  while (!que.empty()) que.pop();
}

int main() {
  int n, m, x, y;
  while (scanf("%d%d%d%d", &n, &m, &x, &y) == 4) {
    mem(gh, -1);
    total = 0;
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    mem(color, -1);
    flag = true;
    while (x--) {
      int u;
      scanf("%d", &u);
      color[u] = 0;
      que.push(u);
    }
    while (y--) {
      int u;
      scanf("%d", &u);
      color[u] = 1;
      que.push(u);
    }
    bfs();
    rep(u, 1, n + 1) if (color[u] == -1) {
      if (gh[u] == -1) flag = false;
      if (!flag) break;
      color[u] = 0;
      que.push(u);
      bfs();
    }
    puts(flag ? "YES" : "NO");
  }
}
