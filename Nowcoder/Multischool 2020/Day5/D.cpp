#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (V.size())

constexpr int maxn = 1010;
int p[maxn], f[maxn];

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &p[i]);
  rep(i, n, n << 1) p[i] = p[i - n];
  int ans = n;
  rep(i, 0, n) {
    int last = 0;
    f[last++] = 0;
    rep(j, 0, n) {
      int index = upper_bound(f, f + last, p[i + j]) - f;
      if (index == last)
        f[last++] = p[i + j];
      else
        f[index] = min(f[index], p[i + j]);
    }
    ans = min(ans, n - last + 1);
  }
  printf("%d\n", ans);
}
