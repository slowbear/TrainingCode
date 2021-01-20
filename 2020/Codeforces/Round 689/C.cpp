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

constexpr int maxn = 2e5 + 7;

int a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  a[0] = -1;
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, n + 1) scanf("%d", &a[i]);
    int pos = n;
    while (a[pos] == pos) --pos;
    double ans = 1.0;
    while (m--) {
      int r;
      double p;
      scanf("%d%lf", &r, &p);
      if (r >= pos) ans *= 1.0 - p;
    }
    if (pos == 0) ans = 0.0;
    printf("%.6f\n", 1.0 - ans);
  }
}
