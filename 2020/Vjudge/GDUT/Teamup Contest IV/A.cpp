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

constexpr int maxn = 101000;

LL a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int n, k;
    LL sum = 0, ans = 0;
    scanf("%d%d", &n, &k);
    rep(i, 0, n) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    if (sum % k) {
      printf("Case #%d: -1\n", ind);
      continue;
    }
    LL block_size = sum / k;
    rep(i, 0, n) {
      if (a[i] >= block_size) {
        ans += (a[i] / block_size) - 1;
        a[i] %= block_size;
        if (a[i]) ++ans;
      }
      if (a[i]) {
        ++ans;
        a[i + 1] += a[i];
      }
    }
    printf("Case #%d: %lld\n", ind, ans);
  }
}
