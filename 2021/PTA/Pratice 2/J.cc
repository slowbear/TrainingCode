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

constexpr int maxn = 101000;

int gh[maxn], gn[maxn], gv[maxn], d[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int dfs(int u, int dep) {
  int ret = dep;
  d[u] = dep;
  grep(i, u) ret = max(ret, dfs(gv[i], dep + 1));
  return ret;
}

int ans[maxn], last = 0;

int main() {
  int n, rt;
  scanf("%d", &n);
  mem(gh, -1);
  total = 0;
  rep(v, 1, n + 1) {
    int u;
    scanf("%d", &u);
    if (u != -1)
      add(u, v);
    else
      rt = v;
  }
  int dd = dfs(rt, 1);
  printf("%d\n", dd);
  rep(i, 1, n + 1) if (d[i] == dd) ans[last++] = i;
  rep(i, 0, last) printf("%d%c", ans[i], " \n"[i == last - 1]);
}
