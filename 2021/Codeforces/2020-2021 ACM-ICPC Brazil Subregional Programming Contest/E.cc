#include <bits/extc++.h>
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

constexpr int maxn = 1e6 + 7, step = 32;

int gh[maxn], gv[maxn], gn[maxn], total;

void add_edge(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int age[maxn], fa[maxn][step];

VI party[maxn];

void dfs(int u) {
  rep(i, 1, step) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  grep(i, u) dfs(gv[i]);
}

int tree[maxn];

inline int lowbit(int x) { return x & (-x); }

void add(int idx, int dx) {
  while (idx < maxn) {
    tree[idx] += dx;
    idx += lowbit(idx);
  }
}

int query(int idx) {
  int result = 0;
  while (idx) {
    result += tree[idx];
    idx ^= lowbit(idx);
  }
  return result;
}

int ans[maxn];

void solve(int u) {
  for (int age : party[u]) add(age, 1);
  ans[u] = query(age[u]);
  grep(i, u) solve(gv[i]);
  for (int age : party[u]) add(age, -1);
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int n, m, rt;
  scanf("%d%d", &n, &m);
  total = 0;
  mem(gh, -1);
  rep(i, 1, n + 1) {
    scanf("%d%d", &age[i], &fa[i][0]);
    if (fa[i][0] == i) {
      rt = i;
    } else {
      add_edge(fa[i][0], i);
    }
  }
  dfs(rt);
  while (m--) {
    int u, l, r;
    scanf("%d%d%d", &u, &l, &r);
    rev(i, 0, step) if (age[fa[u][i]] <= r) u = fa[u][i];
    party[u].pb(l);
  }
  solve(rt);
  rep(i, 1, n + 1) printf("%d%c", ans[i], " \n"[i == n]);
}
