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

int cost[5];

int bound[] = {49, 57, 61, 63, 64};

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    rep(i, 0, 5) scanf("%d", &cost[i]);
    int n;
    scanf("%d", &n);
    LL ans = 0;
    while (n--) {
      int ticket;
      scanf("%d", &ticket);
      rep(i, 0, 5) if (ticket < bound[i]) {
        ans += cost[i];
        break;
      }
    }
    printf("Case #%d: %lld\n", ind, ans * 10000LL);
  }
}
