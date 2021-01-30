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
  int k;
  scanf("%d", &k);
  int keep = 1024 / k;
  printf("%d\n", k + 1023);
  rep(i, 0, 10) { rep(j, 0, 1 << i) printf("1 %d\n", i); }
  while (k--) {
    printf("2 %d", keep);
    rep(i, 0, keep) printf(" %d", 10);
    printf("\n");
  }
}
