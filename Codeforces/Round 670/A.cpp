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

int cnt[1010];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    mem(cnt, 0);
    rep(i, 0, n) {
      int a;
      scanf("%d", &a);
      ++cnt[a];
    }
    int ans = 0, rest = 2;
    rep(i, 0, 101) {
      if (cnt[i] == 0) {
        ans += i * rest;
        rest = 0;
      }
      if (cnt[i] == 1) {
        if (rest & 1) continue;
        ans += i;
        --rest;
      }
      if (!rest) break;
    }
    printf("%d\n", ans);
  }
}
