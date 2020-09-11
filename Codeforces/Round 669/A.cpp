#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pii = pair<int, int>;
using VI = vector<int>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 1010;

int a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, c1 = 0;
    scanf("%d", &n);
    rep(i, 0, n) {
      scanf("%d", &a[i]);
      c1 += a[i];
    }
    int c0 = n - c1;
    if (c0 >= n / 2) {
      printf("%d\n", n / 2);
      rep(i, 0, n / 2) printf("0 ");
    } else {
      int k = n / 2;
      if (k & 1) ++k;
      printf("%d\n", k);
      rep(i, 0, k) printf("1 ");
    }
    printf("\n");
  }
}
