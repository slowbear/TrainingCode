#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int p = 1e9 + 7;

constexpr int maxn = 1e6 + 7;

bool is_prime[maxn];

int prime[maxn], last;

void euler() {
  mem(is_prime, true);
  is_prime[1] = false;
  last = 0;
  rep(i, 2, maxn) {
    if (is_prime[i]) prime[last++] = i;
    rep(j, 0, last) {
      if (1LL * i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (!(i % prime[j])) break;
    }
  }
}

int main() {
  int n;
  LL ans = 1;
  scanf("%d", &n);
  euler();
  rep(i, 0, last) {
    if (prime[i] > n) break;
    int cnt = 0, cur = n;
    while (cur) cnt += (cur /= prime[i]);
    ans = ans * (2 * cnt + 1) % p;
  }
  printf("%lld\n", ans);
}
