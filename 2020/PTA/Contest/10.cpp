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

int suffix[maxn], middle[maxn];

int gh[maxn], gv[maxn], gn[maxn], total;

void add(int u, int v) {
  if (!v) return;
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int build_tree(int suffix[], int middle[], int n) {
  if (!n) return 0;
  int rt = suffix[n - 1], rt_index;
  rep(i, 0, n) if (middle[i] == rt) rt_index = i;
  int u = build_tree(suffix, middle, rt_index);
  int v = build_tree(suffix + rt_index, middle + rt_index + 1, n - rt_index - 1);
  add(rt, v);
  add(rt, u);
  return rt;
}

bool vis[maxn];

void bfs(int s) {
  queue<int> que;
  que.push(s);
  vis[s] = true;
  VI ans;
  while (!que.empty()) {
    int u = que.front();
    ans.pb(u);
    que.pop();
    grep(i, u) {
      int v = gv[i];
      if (!vis[v]) {
        vis[v] = true;
        que.push(v);
      }
    }
  }
  printf("%d", ans[0]);
  rep(i, 1, SZ(ans)) printf(" %d", ans[i]);
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  total = 0;
  mem(gh, -1);
  rep(i, 0, n) scanf("%d", &suffix[i]);
  rep(i, 0, n) scanf("%d", &middle[i]);
  int rt = build_tree(suffix, middle, n);
  bfs(rt);
}
