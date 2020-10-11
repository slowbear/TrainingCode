#include <bits/stdc++.h>

#include <algorithm>
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

constexpr int maxn = 100;

VI a[maxn];

void solve(const VI &x, const VI &y) {
  int i = 0, j = 0, nc = 0, nt = 0;
  while (i < x.size() && j < y.size()) {
    if (x[i] < y[j]) {
      ++nt;
      ++i;
    } else if (x[i] > y[j]) {
      ++nt;
      ++j;
    } else {
      ++nt;
      nc += 1;
      ++i;
      ++j;
    }
  }
  // while (i < x.size()) ++nt, ++i;
  // while (j < y.size()) ++nt, ++j;
  nt += (x.size() - i) + (y.size() - j);
  printf("%.2f%%\n", 100.0 * nc / nt);
}

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 1, n + 1) {
    int sz;
    scanf("%d", &sz);
    while (sz--) {
      int x;
      scanf("%d", &x);
      a[i].pb(x);
    }
    sort(a[i].begin(), a[i].end());
    a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    solve(a[l], a[r]);
  }
}
