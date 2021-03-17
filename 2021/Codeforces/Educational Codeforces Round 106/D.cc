#include <bits/extc++.h>
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

constexpr int maxn = 2e7 + 7;

int prime[maxn], cnt[maxn], last;

bool is_prime[maxn];

void euler() {
  mem(is_prime, true);
  is_prime[1] = false;
  cnt[1] = 0;
  last = 0;
  rep(i, 2, maxn) {
    if (is_prime[i]) {
      prime[last++] = i;
      cnt[i] = 1;
    }
    rep(j, 0, last) {
      if (1LL * i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (i % prime[j]) {
        cnt[i * prime[j]] = cnt[i] + 1;
      } else {
        cnt[i * prime[j]] = cnt[i];
        break;
      }
    }
  }
}

// LL calc(LL x) {
//   int cnt = 0;
//   rep(i, 0, last) {
//     if (x == 1) break;
//     if (x % prime[i]) continue;
//     ++cnt;
//     while (!(x % prime[i])) x /= prime[i];
//   }
//   if (x != 1) ++cnt;
//   return 1LL << cnt;
// }

int main() {
  int T;
  scanf("%d", &T);
  euler();
  while (T--) {
    LL c, d, x, ans = 0;
    scanf("%lld%lld%lld", &c, &d, &x);
    for (LL f = 1; 1LL * f * f <= x; ++f) {
      if (!(x % f)) {
        if (!((x + d * f) % (c * f)))
          // ans += calc((x + d * f) / (c * f));
          ans += 1LL << cnt[(x + d * f) / (c * f)];
        if (!((x + d * (x / f)) % (c * (x / f))) && (f != x / f))
          // ans += calc((x + d * (x / f)) / (c * (x / f)));
          ans += 1LL << cnt[(x + d * (x / f)) / (c * (x / f))];
      }
    }
    printf("%lld\n", ans);
  }
}
