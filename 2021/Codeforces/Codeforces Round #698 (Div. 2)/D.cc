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

LL x[maxn], diff[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    LL k;
    scanf("%d %lld", &n, &k);
    rep(i, 0, n) scanf("%lld", &x[i]);
    sort(x, x + n);
    rep(i, 1, n) diff[i] = x[i] - x[i - 1];
    rep(i, 1, n) diff[1] = __gcd(diff[1], diff[i]);
    bool flag = false;
    rep(i, 0, n) {
      if ((k - x[i]) % diff[1] == 0) {
        flag = true;
        break;
      }
    }
    puts(flag ? "YES" : "NO");
  }
}
