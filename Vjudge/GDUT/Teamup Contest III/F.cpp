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

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("Case #%d:", ind);
    rep(i, 1, k + 1) printf(" %d", i);
    rev(i, k + 1, 2 * k + 1) printf(" %d", i);
    rep(i, 2 * k + 1, n + 1) printf(" %d", i);
    printf("\n");
  }
}
