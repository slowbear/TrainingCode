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

VI pos, neg;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    pos.clear();
    neg.clear();
    LL ans = 1;
    rep(i, 0, n) {
      int num;
      scanf("%d", &num);
      if (i < 5) ans *= num;
      if (num >= 0)
        pos.pb(num);
      else
        neg.pb(-num);
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end(), greater<int>());
    rep(i, 0, 6) {
      LL cur = 1;
      if (i > SZ(neg)) continue;
      if (5 - i > SZ(pos)) continue;
      if (i & 1) {
        rep(j, SZ(neg) - i, SZ(neg)) cur *= -neg[j];
        rep(j, SZ(pos) - (5 - i), SZ(pos)) cur *= pos[j];
      } else {
        rep(j, 0, i) cur *= -neg[j];
        rep(j, 0, 5 - i) cur *= pos[j];
      }
      ans = max(ans, cur);
    }
    printf("%lld\n", ans);
  }
}
