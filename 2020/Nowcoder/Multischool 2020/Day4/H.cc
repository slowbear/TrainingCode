#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (V.size())

constexpr int maxn = 201000;

VI vec[maxn];
int prime[maxn], last;
bool is_prime[maxn];

void select() {
  mem(is_prime, 1);
  last = 0;
  rep(i, 2, maxn) {
    if (is_prime[i]) prime[last++] = i;
    rep(j, 0, last) {
      if (1LL * i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}

VP ans;
bool done[maxn];

int main() {
  int T;
  scanf("%d", &T);
  select();
  while (T--) {
    int n;
    scanf("%d", &n);
    ans.clear();
    rep(i, 2, n) done[i] = false;
    int tot = lower_bound(prime, prime + last, n) - prime;
    for (int i = tot; i >= 0; --i) {
      int p = prime[i], peer = p;
      for (int j = n / p * p; j > p; j -= p) {
        if (done[j]) continue;
        if (peer != -1) {
          ans.pb(mp(peer, j));
          done[j] = true;
          done[peer] = true;
          peer = -1;
        } else {
          peer = j;
        }
      }
    }
    int len = ans.size();
    printf("%d\n", len);
    for (auto e : ans) printf("%d %d\n", e.first, e.second);
  }
}
