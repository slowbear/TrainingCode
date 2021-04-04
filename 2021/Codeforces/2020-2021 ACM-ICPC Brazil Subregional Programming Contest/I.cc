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

constexpr int maxn = 2e5 + 7, p = 1e9 + 7;

int gh[maxn], gv[maxn], gn[maxn], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

LL f[maxn][2];

void dfs(int u) {
  if (gh[u] != -1) {
    f[u][0] = 1;
    int last = 0;
    vector<LL> c, elem;
    grep(i, u) {
      int v = gv[i];
      dfs(v);
      LL cur = (f[v][0] + f[v][1]) % p;
      f[u][0] = cur * f[u][0] % p;
      elem.pb(cur);
      c.pb(f[v][1]);
      ++last;
    }
    vector<LL> a(last), b(last);
    a[0] = 1;
    rep(i, 1, last) a[i] = a[i - 1] * elem[i - 1] % p;
    b[last - 1] = 1;
    rev(i, 0, last - 1) b[i] = b[i + 1] * elem[i + 1] % p;
    f[u][1] = 0;
    rep(i, 0, last) f[u][1] = (a[i] * b[i] % p * c[i] % p + f[u][1]) % p;
  } else {
    f[u][0] = 0;
    f[u][1] = 1;
  }
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  total = 0;
  mem(gh, -1);
  rep(i, 2, n + 1) {
    int fa;
    scanf("%d", &fa);
    add(fa, i);
  }
  dfs(1);
  printf("%lld\n", (f[1][0] + f[1][1]) % p);
}
