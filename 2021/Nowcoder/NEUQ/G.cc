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

constexpr int maxn = 1e5 + 7;

LL a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    LL n, k;
    scanf("%lld%lld", &n, &k);
    rep(i, 0, n) scanf("%lld", &a[i]);
    int pos = max_element(a, a + n) - a;
    LL x = a[pos];
    LL l = 0, r = 0, ll = 0, rr = 0;
    rep(i, 0, pos) {
      ++l;
      r += a[i];
    }
    rep(i, pos + 1, n) {
      ++ll;
      rr += a[i];
    }
    k -= l + 1;
    LL limit = r + x - l;
    if (k < 0) {
      puts("NO");
    } else if (k < limit) {
      puts("YES");
    } else {
      LL lll = l + ll + x, rrr = r + rr + x;
      LL times = k / lll;
      k %= lll;
      k = max(0LL, k - times * (rrr - lll));
      puts(k < limit ? " YES" : "NO");
    }
  }
}
