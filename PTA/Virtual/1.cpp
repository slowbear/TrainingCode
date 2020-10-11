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

constexpr int maxn = 101000;

bool single[maxn], always_single[maxn];

int main() {
  int n;
  scanf("%d", &n);
  mem(single, 1);
  mem(always_single, 0);
  rep(i, 0, n) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      int id;
      scanf("%d", &id);
      continue;
    }
    rep(j, 0, k) {
      int id;
      scanf("%d", &id);
      single[id] = false;
    }
  }
  int m;
  scanf("%d", &m);
  bool none = true;
  while (m--) {
    int id;
    scanf("%d", &id);
    if (single[id]) {
      printf(none ? "%05d" : " %05d", id);
      single[id] = false;
      none = false;
    }
  }
  printf(none ? "No one is handsome\n" : "\n");
}
