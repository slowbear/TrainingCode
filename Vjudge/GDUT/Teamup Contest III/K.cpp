// TODO: Fixed calculate error.
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
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

constexpr ULL p = 1000000007;

ULL ni[10];

void init() {
  ni[1] = 1;
  rep(i, 2, 10) ni[i] = (p - p / i) * ni[p % i] % p;
}

ULL cnt(ULL x) {
  ULL ans = 0;
  while (x) {
    ++ans;
    x &= (x - 1);
  }
  return ans;
}

ULL count_zero(ULL x) {
  ULL ans = x ? -1 : 0;
  while (x) {
    ++ans;
    x >>= 1;
  }
  return ans;
}

ULL cnt_prefix(ULL x) {
  ULL ans = 0, cur = cnt(x);
  while (x) {
    ULL new_x = x & (x - 1);
    ++ans;
    ans += (x - new_x) * (--cur) % p;
    ans %= p;
    ans += (x - new_x) * ni[2] % p * count_zero(x - new_x) % p;
    ans %= p;
    x = new_x;
  }
  return ans;
}

ULL cnt_lca_prefix(ULL x) {
  // ULL ans = 0, cur = cnt(x);
  // while (x) {
  //   ULL new_x = x & (x - 1);
  //   ans += (x - new_x) * (--cur) % p;
  //   ans %= p;
  //   ULL b = count_zero(x - new_x);
  //   b = b * (b - 1) % p;
  //   ans += (x - new_x) * b % p * ni[8] % p;
  //   x = new_x;
  // }
  // return ans;
  ULL ans = 0;
  rev(i, 0, 63) {
    ULL cur = 1ULL << i;
    if (cur & x) {
      ULL b = count_zero(cur);
      b = b * (b - 1) * ni[8] % p;
      ans = (ans + cur % p * b % p) % p;
      x ^= cur;
      ans = (ans + cur) % p;
    }
  }
  return ans;
}

int main() {
  // init();
  // rep(i, 1, 100) printf("f(%d)=%llu\n", i, cnt_prefix(i));
  int T;
  scanf("%d", &T);
  init();
  rep(i, 1, T + 1) {
    ULL n;
    scanf("%llu", &n);
    ULL ans = n % p * cnt_prefix(n) % p;
    ans -= 2 * cnt_lca_prefix(n + 1) % p;
    ans = (ans % p + p) % p;
    printf("Case #%d: %llu\n", i, ans);
  }
}
