#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int cnt[2][3];
    rep(i, 0, 2) rep(j, 0, 3) scanf("%d", &cnt[i][j]);
    LL ans = 0;
    int k1 = min(cnt[0][2], cnt[1][1]);
    ans += 2LL * k1;
    cnt[0][2] -= k1;
    cnt[1][1] -= k1;
    cnt[0][1] -= min(cnt[1][0] + cnt[1][1], cnt[0][1]);
    ans -= 2LL * cnt[0][1];
    printf("%lld\n", ans);
  }
}
