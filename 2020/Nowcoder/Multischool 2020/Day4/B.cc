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

constexpr int p = 1e9 + 7;
constexpr int maxn = 1010000;
bool is_prime[maxn];
int pf[maxn], prime[maxn], last;

void select() {
  mem(is_prime, true);
  is_prime[1] = false;
  last = 0;
  rep(i, 2, maxn) {
    if (is_prime[i]) {
      prime[last++] = i;
      pf[i] = i;
    }
    rep(j, 0, last) {
      if (1LL * i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      pf[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}

LL my_pow(LL a, LL b, LL p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  LL ans = my_pow(a, b >> 1, p);
  ans = ans * ans % p;
  if (b & 1) ans = ans * a % p;
  return ans;
}

int calc[maxn];

int main() {
  int T;
  scanf("%d", &T);
  pf[1] = 1;
  select();
  calc[1] = 0;
  rep(i, 2, maxn) calc[i] = calc[i / pf[i]] + 1;
  while (T--) {
    int n, c;
    scanf("%d%d", &n, &c);
    printf("%lld\n", my_pow(c, calc[n], p));
  }
}
