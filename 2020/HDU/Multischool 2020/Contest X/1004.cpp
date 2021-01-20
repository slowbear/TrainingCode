#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 5010;

constexpr int p = 1e9 + 7;

int f[2][maxn], suffix[2][maxn], prefix[2][maxn];

int op[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &op[i]);
    int cur = 0;
    f[cur][1] = prefix[cur][1] = suffix[cur][1] = 1;
    rep(i, 1, n) {
      rep(j, 1, i + 2) {
        f[cur ^ 1][j] = op[i] ? (j ? prefix[cur][j - 1] : 0) : (j == i + 1 ? 0 : suffix[cur][j]);
      }
      cur ^= 1;
      prefix[cur][1] = f[cur][1];
      rep(j, 2, i + 2) prefix[cur][j] = (prefix[cur][j - 1] + f[cur][j]) % p;
      suffix[cur][i + 1] = f[cur][i + 1];
      for (int j = i; j; --j) suffix[cur][j] = (suffix[cur][j + 1] + f[cur][j]) % p;
    }
    printf("%d\n", prefix[cur][n]);
  }
}
