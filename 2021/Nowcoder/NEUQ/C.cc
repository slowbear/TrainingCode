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
using namespace std;

constexpr int maxn = 1e6 + 7;

LL a[maxn];

int f[maxn];

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%lld", &a[i]);
  f[0] = 1;
  LL ans = 1;
  rep(i, 1, n) {
    f[i] = (a[i - 1] <= a[i] ? f[i - 1] + 1 : 1);
    ans += f[i];
  }
  printf("%lld\n", ans);
}
