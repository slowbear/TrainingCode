#include <bits/extc++.h>
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

constexpr int maxm = 1e5 + 7;

int cnt[maxm];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 0, m) cnt[i] = 0;
    rep(i, 0, n) {
      int a;
      scanf("%d", &a);
      ++cnt[a % m];
    }
    int ans = cnt[0] > 0;
    rep(i, 1, m) {
      if (i > m - i) break;
      if (i == m - i) {
        if (cnt[i]) ++ans;
        break;
      }
      if (!cnt[i] && !cnt[m - i]) continue;
      ans += abs(cnt[i] - cnt[m - i]);
      if (cnt[i] == cnt[m - i]) ++ans;
      // if (!cnt[i]) continue;
      // if (cnt[i] <= cnt[m - i]) {
      //   ++ans;
      //   cnt[m - i] -= min(cnt[m - i], cnt[i] + 1);
      //   cnt[i] = 0;
      // } else {
      //   ++ans;
      //   cnt[i] -= cnt[m - i] + 1;
      //   cnt[m - i] = 0;i
      //   ans += cnt[i];
      //   cnt[i] = 0;
      // }
    }
    printf("%d\n", ans);
  }
}
