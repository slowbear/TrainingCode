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

constexpr int maxn = 201000;

int a[maxn], f[maxn][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &a[i]);
    if (n == 1) {
      printf("%d\n", a[0]);
      continue;
    }
    f[0][0] = n;
    f[0][1] = a[0];
    f[1][0] = a[0];
    f[1][1] = a[0] + a[1];
    rep(i, 2, n) {
      f[i][0] = min(f[i - 1][1], f[i - 2][1]);
      f[i][1] = min(f[i - 1][0] + a[i], f[i - 2][0] + a[i] + a[i - 1]);
    }
    printf("%d\n", min(f[n - 1][0], f[n - 1][1]));
  }
}
