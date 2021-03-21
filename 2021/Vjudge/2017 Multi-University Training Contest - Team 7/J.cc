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

constexpr int maxn = 2e5 + 7;

int a[maxn];

inline int lowbit(int x) { return x & (-x); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 0, n) scanf("%d", &a[i]);
    while (m) {
      int gap = lowbit(m);
      rep(i, gap, n) a[i] = a[i - gap] ^ a[i];
      m ^= gap;
    }
    rep(i, 0, n) printf("%d%c", a[i], " \n"[i == n - 1]);
  }
}
