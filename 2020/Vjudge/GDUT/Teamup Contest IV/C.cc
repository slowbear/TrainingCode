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
  rep(i, 1, T + 1) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &a[i]);
    rev(i, 1, n) a[i] -= a[i - 1];
    LL cur = 1, ans = 1;
    rev(i, 0, n - 1) {
      cur *= a[i];
      cur = (cur + a[i + 1] - 1) / a[i + 1];
      ans += cur;
    }
    printf("Case #%d: %lld\n", i, ans);
  }
}
