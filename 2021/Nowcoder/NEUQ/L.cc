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

LL a[maxn];

int n, k;

bool check(LL dis) {
  LL rest = k;
  rep(i, 1, n) {
    rest -= (a[i] - a[i - 1] - 1) / dis;
    if (rest < 0) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  rep(i, 0, n) scanf("%lld", &a[i]);
  sort(a, a + n);
  LL l = 0, r = 1e12 + 7;
  while (l < r) {
    LL mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", r);
}
