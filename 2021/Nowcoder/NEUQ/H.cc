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

constexpr int p = 998244353;

LL quick_pow(LL a, LL b, int p) {
  if (!b) return 1;
  LL ret = quick_pow(a, b >> 1, p);
  ret = ret * ret % p;
  if (b & 1) ret = ret * a % p;
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == 0) {
      if (n == 0) printf("%d\n", 1);
      if (n == 1) printf("%d\n", 2);
      if (n > 1) printf("%d\n", (n + 2) % p);
    }
    if (m == 1) {
      if (n == 0)
        printf("%d\n", 1);
      else
        printf("%lld\n", 2LL * n % p);
    }
    if (m == 2) {
      if (n == 0)
        printf("%d\n", 1);
      else
        printf("%lld\n", quick_pow(2, n, p));
    }
  }
}
