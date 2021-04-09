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

constexpr int maxm = 1e5 + 7, maxn = 1e4 + 7;

int f[maxm], c[maxn], w[maxn];

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  rep(i, 0, n) scanf("%d%d", &c[i], &w[i]);
  mem(f, 0);
  rep(i, 0, n) rev(j, c[i], m + 1) f[j] = max(f[j], f[j - c[i]] + w[i]);
  printf("%d\n", f[m]);
}
