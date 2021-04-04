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
#define SZ(V) (int)(V.size())

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n & 1) {
    if (k != 0) {
      printf("-1\n");
      return 0;
    }
    rep(i, 1, n / 2 + 1) printf("%d %d ", i, n - i);
    printf("%d\n", n);
  } else {
    if (k != n / 2) {
      printf("-1\n");
      return 0;
    }
    rep(i, 1, n / 2) printf("%d %d ", i, n - i);
    printf("%d %d\n", n / 2, n);
  }
}
