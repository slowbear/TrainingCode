#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define VI vector<int>
#define SZ(V) (V.size())

constexpr int maxn = 201000;

LL a[maxn], f[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &a[i]);
    sort(a, a + n);
    int ch = 0;
    f[0] = 0;
    f[1] = -1;
    rep(i, 2, n / 2 + 1) {
      int j = i - 2;
      if (f[j] != -1) {
        if (f[j] - 2 * a[2 * j] < f[ch] - 2 * a[2 * ch]) ch = j;
      }
      f[i] = f[ch] + 2 * (a[2 * i - 1] - a[2 * ch]);
    }
    printf("%lld\n", f[n / 2]);
  }
}
