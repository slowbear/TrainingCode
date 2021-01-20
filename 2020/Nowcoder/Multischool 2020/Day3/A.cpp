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

constexpr int maxn = 2001000;

int n, a[maxn];
char str[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf(" %s", str);
    rep(i, 0, n) a[i] = str[i] - '0';
    int ans = 0;
    rep(i, 0, n) if (a[i] > 1) { ++ans; }
    int cur = 0;
    rep(i, 0, n) {
      if (a[i] == 1) cur++;
      if ((a[i] == 0) && cur) {
        ++ans;
        --cur;
      }
    }
    ans += cur / 2;
    printf("%d\n", ans);
  }
}
