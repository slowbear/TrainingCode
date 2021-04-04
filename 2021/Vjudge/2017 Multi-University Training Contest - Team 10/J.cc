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

Pii a[maxn];

multimap<int, int> f;

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    f.clear();
    rep(i, 0, n) {
      auto g = f.upper_bound(a[i].first);
      if (g == f.begin()) {
        f.insert({a[i].second, a[i].second - a[i].first});
        continue;
      }
      --g;
      auto h = mp(g->first, g->second);
      f.erase(g);
      h.second += a[i].second - h.first;
      h.first = a[i].second;
      f.insert(h);
    }
    LL sum = 0;
    for (auto i : f) sum += i.second;
    printf("%d %lld\n", SZ(f), sum);
  }
}
