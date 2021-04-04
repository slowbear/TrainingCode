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

constexpr int maxn = 1e6 + 7;

constexpr LL limmit = 4e9 + 7;

int a[maxn], n;

bool check(LL x) {
  LL cur = 0;
  rep(i, 0, n) cur += max(x - a[i], 0LL);
  return cur <= x;
}

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &a[i]);
    LL l = 0, r = limmit;
    while (l + 1 < r) {
      LL mid = l + (r - l) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    printf("Case #%d: %lld\n", index, l + 1);
  }
}
