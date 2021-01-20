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

constexpr int maxn = 1e5 + 7;

LL a[maxn], prefix[maxn];

LL keep[maxn * 30], last;

int main() {
  int T;
  scanf("%d", &T);
  queue<Pii> que;
  while (T--) {
    int n, q;
    scanf("%d%d", &n, &q);
    rep(i, 1, n + 1) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    prefix[0] = 0;
    rep(i, 1, n + 1) prefix[i] = prefix[i - 1] + a[i];
    que.push({1, n + 1});
    last = 0;
    while (!que.empty()) {
      auto u = que.front();
      que.pop();
      if (u.first >= u.second) continue;
      keep[last++] = prefix[u.second - 1] - prefix[u.first - 1];
      if (a[u.first] == a[u.second - 1]) continue;
      LL mid = (a[u.first] + a[u.second - 1]) / 2;
      int pos = upper_bound(a + u.first, a + u.second, mid) - a;
      que.push({u.first, pos});
      que.push({pos, u.second});
    }
    keep[last] = 0;
    sort(keep, keep + last);
    while (q--) {
      LL val;
      scanf("%lld", &val);
      LL calc = *lower_bound(keep, keep + last, val);
      puts(val == calc ? "Yes" : "No");
    }
  }
}
