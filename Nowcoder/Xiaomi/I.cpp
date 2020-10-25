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

constexpr int maxn = 1024;

char a[maxn][maxn];

int dx[256], dy[256];

bool f[maxn][maxn];

int vis[maxn][maxn];

int n, m;

bool valid(int x, int y) { return (1 <= x) && (x <= n) && (1 <= y) && (y <= m); }

bool dfs(int x, int y, int step) {
  if (!valid(x, y)) return true;
  if (vis[x][y]) {
    if (vis[x][y] != step)
      return f[x][y];
    else
      return f[x][y] = false;
  }
  vis[x][y] = step;
  return f[x][y] = dfs(x + dx[a[x][y]], y + dy[a[x][y]], step);
}

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n + 1) rep(j, 1, m + 1) scanf(" %c", &a[i][j]);
  dx['W'] = -1;
  dx['A'] = 0;
  dx['S'] = 1;
  dx['D'] = 0;
  dy['W'] = 0;
  dy['A'] = -1;
  dy['S'] = 0;
  dy['D'] = 1;
  int cur = 1;
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    dfs(i, j, cur);
    ++cur;
  }
  int ans = 0;
  rep(i, 1, n + 1) rep(j, 1, m + 1) if (f[i][j])++ ans;
  printf("%d\n", ans);
}
