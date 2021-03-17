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

constexpr int maxn = 2e5 + 7;

char str[maxn];

int f[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int m;
    scanf("%d %s", &m, str);
    int len = strlen(str), ans = 0;
    f[0] = 0;
    //! Odd
    rep(i, 1, len) {
      int l = i + 1, r = i + 1, cur = 0;
      f[i] = 0;
      while (l < len) {
        while (r < len && 2 * i - r >= 0) {
          if (cur + abs(str[r] - str[2 * i - r]) <= m) {
            cur += abs(str[r] - str[2 * i - r]);
            ++r;
          } else {
            break;
          }
        }
        f[i] = max(f[i], r - l);
        if (f[i] > ans) ans = f[i];
        cur -= abs(str[l] - str[2 * i - l]);
        ++l;
      }
    }
    //! Even
    rep(i, 1, len) {
      int l = i, r = i, cur = 0;
      while (l < len) {
        while (r < len && 2 * i - 1 - r >= 0) {
          if (cur + abs(str[r] - str[2 * i - 1 - r]) <= m) {
            cur += abs(str[r] - str[2 * i - 1 - r]);
            ++r;
          } else {
            break;
          }
        }
        f[i] = max(f[i], r - l);
        if (f[i] > ans) ans = f[i];
        cur -= abs(str[l] - str[2 * i - 1 - l]);
        ++l;
      }
    }
    printf("%d\n", ans);
  }
}
