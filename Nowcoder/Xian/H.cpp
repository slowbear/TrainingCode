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

int a[maxn], b[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  rep(i, 0, n) scanf("%d", &a[i]);
  int block_size = sqrt(n), block_cnt = (n - 1) / block_size;
  rep(i, 0, n) {
    int id = i / block_size;
    if (!b[id] || (a[i] < b[id])) b[id] = a[i];
  }
  while (m--) {
    int opt;
    scanf("%d", &opt);
    if (opt & 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x;
      a[x] = y;
      b[x / block_size] = y;
      int l = x / block_size * block_size, r = min(l + block_size, n);
      rep(i, l, r) if (a[i] < b[i / block_size]) b[i / block_size] = a[i];
    } else {
      int x, pre = -1, suf = n;
      scanf("%d", &x);
      --x;
      int l = x / block_size * block_size, r = l + block_size;
      rev(i, l, x) if (a[i] < a[x]) {
        pre = i;
        break;
      }
      if (pre == -1) {
        int id = x / block_size - 1;
        while (id && (b[id] > a[x])) --id;
        int l = id * block_size, r = l + block_size;
        rev(i, l, r) if (a[i] < a[x]) {
          pre = i;
          break;
        }
      }
      rep(i, x + 1, r) if (a[i] < a[x]) {
        suf = i;
        break;
      }
      if (suf == n) {
        int id = x / block_size + 1;
        while ((id < block_cnt) && (b[id] > a[x])) ++id;
        int l = id * block_size, r = min(l + block_size, n);
        rep(i, l, r) if (a[i] < a[x]) {
          suf = i;
          break;
        }
      }
      printf("%lld\n", 1LL * (x - pre) * (suf - x));
    }
  }
}
