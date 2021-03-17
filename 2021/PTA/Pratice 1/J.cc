#include <bits/extc++.h>
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

int a[maxn], f[maxn];

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &a[i]);
  int ans = 0;
  f[0] = 0;
  rep(i, 0, n) {
    int l = 0, r = ans + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (a[i] > f[mid])
        l = mid;
      else
        r = mid;
    }
    if (l == ans) f[++ans] = a[i];
    f[l + 1] = min(f[l + 1], a[i]);
  }
  printf("%d\n", ans);
}
