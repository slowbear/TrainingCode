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

unordered_map<int, int> pos;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    rep(i, 1, n + 1) scanf("%lld", &a[i]);
    a[0] = 0;
    rep(i, 1, n + 1) a[i] += a[i - 1];
    rep(i, 1, n + 1) a[i] %= k;
    int ans = -1;
    pos.clear();
    pos[0] = 0;
    rep(i, 1, n + 1) {
      if (pos.find(a[i]) != pos.end()) {
        ans = max(ans, i - pos[a[i]]);
      } else {
        pos[a[i]] = i;
      }
    }
    printf("%d\n", ans);
  }
}
