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

int main() {
  LL n, x, y;
  scanf("%lld%lld%lld", &n, &x, &y);
  LL total = n * n - 1;
  if (x + y > n - 1) {
    x = n - 1 - x;
    y = n - 1 - y;
    LL ans = (x + y);
    ans = ans * (ans + 1) / 2 + x;
    printf("%lld\n", total - ans);
  } else {
    LL ans = (x + y);
    ans = ans * (ans + 1) / 2;
    printf("%lld\n", ans + x);
  }
}
