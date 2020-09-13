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

constexpr int maxn = 201000;

int n;

LL a[maxn], ans;

inline void change(int ind, LL val) {
  if (ind < n) {
    if (a[ind] > 0 || !ind) ans -= a[ind];
    a[ind] = val;
    if (a[ind] > 0 || !ind) ans += a[ind];
  }
}

inline LL calc(LL x) { return x > 0 ? (x + 1) / 2 : x / 2; }

int main() {
  scanf("%d", &n);
  rep(i, 0, n) scanf("%lld", &a[i]);
  rev(i, 1, n) a[i] -= a[i - 1];
  ans = a[0];
  rep(i, 1, n) if (a[i] > 0) ans += a[i];
  printf("%lld\n", calc(ans));
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    --l;
    --r;
    change(l, a[l] + x);
    change(r + 1, a[r + 1] - x);
    printf("%lld\n", calc(ans));
  }
}
