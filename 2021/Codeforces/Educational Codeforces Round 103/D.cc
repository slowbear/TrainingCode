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

constexpr int maxn = 3e5 + 7;

char a[maxn];

int f[maxn][2], g[maxn][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    a[0] = ' ';
    scanf(" %s", a + 1);
    f[0][0] = f[0][1] = 0;
    rep(i, 1, n + 1) {
      f[i][0] = (a[i] == 'L' ? f[i - 1][1] + 1 : 0);
      f[i][1] = (a[i] == 'R' ? f[i - 1][0] + 1 : 0);
    }
    g[n + 1][0] = g[n + 1][1] = 0;
    rev(i, 1, n + 1) {
      g[i][0] = (a[i] == 'L' ? g[i + 1][1] + 1 : 0);
      g[i][1] = (a[i] == 'R' ? g[i + 1][0] + 1 : 0);
    }
    rep(i, 0, n + 1) printf("%d%c", f[i][0] + g[i + 1][1] + 1, " \n"[i == n]);
  }
}
