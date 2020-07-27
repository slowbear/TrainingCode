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

int b[110];
double c[110];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d%lf", &b[i], &c[i]);
    rep(i, 0, n) c[i] = 1 - c[i];
    rep(i, 1, n) {
      if (c[i] / (c[i] + b[i]) > c[0] / (c[0] + b[0])) {
        c[0] = c[i];
        b[0] = b[i];
      }
    }
    printf("%.5f\n", c[0] / (c[0] + b[0]));
  }
}
