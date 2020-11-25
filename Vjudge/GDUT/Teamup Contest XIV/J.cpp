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

LL a[maxn], b[maxn], c[maxn];

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &a[i]);
    b[0] = a[0];
    rep(i, 1, n) b[i] = a[i] - a[i - 1];
    b[n] = -a[n - 1];
    fill(c, c + n + 1, 0);
    bool valid = true;
    rep(i, 0, n) {
      if (b[i] <= 0) {
        if (c[i] < -b[i]) valid = false;
        c[i] += b[i];
      } else {
        if (i + 3 > n) valid = false;
        c[i + 3] += b[i];
      }
      if (!valid) break;
      c[i + 1] += c[i];
    }
    valid = valid && !(b[n] + c[n]);
    printf("Case #%d: %s\n", ind, valid ? "Yes" : "No");
  }
}
