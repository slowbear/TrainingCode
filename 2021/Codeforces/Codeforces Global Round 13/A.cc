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

constexpr int maxn = 1e5 + 7;

int a[maxn];

int main() {
  int n, q;
  int cnt = 0;
  scanf("%d%d", &n, &q);
  rep(i, 1, n + 1) {
    scanf("%d", &a[i]);
    cnt += a[i];
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x & 1) {
      cnt -= a[y];
      a[y] ^= 1;
      cnt += a[y];
    } else {
      puts(((y <= cnt) && cnt) ? "1" : "0");
    }
  }
}
