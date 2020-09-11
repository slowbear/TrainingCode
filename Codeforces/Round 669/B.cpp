#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pii = pair<int, int>;
using VI = vector<int>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 1010;

vector<int> cnt[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, top = 0;
    scanf("%d", &n);
    rep(i, 0, maxn) cnt[i].clear();
    rep(i, 0, n) {
      int a;
      scanf("%d", &a);
      cnt[a].push_back(a);
      if (a > top) top = a;
    }
    int cur = top;
    rev(i, 1, top + 1) {
      if (cnt[i].empty()) continue;
      if (cur % i) {
        int p = __gcd(cur, i);
        for (int x : cnt[i]) cnt[p].pb(x);
      } else {
        for (int x : cnt[i]) printf("%d ", x);
        cur = i;
      }
    }
    printf("\n");
  }
}
