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

constexpr int maxm = 1e4 + 7;

int cnt[maxm], ans[maxm];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 0, m + 1) scanf("%d", &cnt[i]);
    rep(i, 1, m + 1) cnt[i] /= cnt[0];
    int cur = 1, last = 0;
    while (cnt[0] > 1) {
      cnt[0] >>= 1;
      ans[last++] = 0;
    }
    while (true) {
      while (cur <= m && !cnt[cur]) ++cur;
      if (cur > m) break;
      ans[last++] = cur;
      rep(i, cur, m + 1) cnt[i] -= cnt[i - cur];
    }
    rep(i, 0, last) printf("%d%c", ans[i], " \n"[i == last - 1]);
  }
}
