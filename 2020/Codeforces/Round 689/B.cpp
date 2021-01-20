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

constexpr int maxn = 510;

char c[maxn][maxn];

int ex[maxn][maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, n + 1) rep(j, 1, m + 1) scanf(" %c", &c[i][j]);
    rep(i, 1, n + 1) rep(j, 1, m + 1) ex[i][j] = c[i][j] == '*';
    rev(i, 1, n + 1) rev(j, 1, m + 1) if (ex[i][j]) ex[i][j] =
        min(ex[i + 1][j - 1], min(ex[i + 1][j], ex[i + 1][j + 1])) + 1;
    LL ans = 0;
    rep(i, 1, n + 1) rep(j, 1, m + 1) ans += ex[i][j];
    printf("%lld\n", ans);
    rep(i, 1, n + 1) rep(j, 1, m + 1) c[i][j] = '\0';
    rep(i, 1, n + 1) rep(j, 1, m + 1) ex[i][j] = 0;
  }
}
