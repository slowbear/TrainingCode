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

constexpr int maxn = 1e7 + 9;

int cnt[maxn], f[maxn];

bool not_prime[maxn];

int prime[maxn], total;

void euler() {
  rep(i, 2, maxn) {
    if (!not_prime[i]) prime[total++] = i;
    rep(j, 0, total) {
      if (1LL * i * prime[j] >= maxn) break;
      not_prime[i * prime[j]] = true;
      if (!(i % prime[j])) break;
    }
  }
}

int a[maxn];

int main() {
  int n;
  scanf("%d", &n);
  euler();
  rep(i, 0, n) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  int ans = 0;
  rep(i, 2, maxn) {
    if (f[i] + cnt[i] + cnt[1] > ans) ans = f[i] + cnt[i] + cnt[1];
    rep(j, 0, total) {
      if (i * prime[j] >= maxn) break;
      if (f[i] + cnt[i] > f[i * prime[j]]) f[i * prime[j]] = f[i] + cnt[i];
    }
  }
  printf("%d\n", ans);
}
