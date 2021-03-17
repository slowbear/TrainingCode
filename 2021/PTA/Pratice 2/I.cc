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

constexpr int maxm = 10100;

int u[maxm], v[maxm];

set<int> cur;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  rep(i, 0, m) scanf("%d%d", &u[i], &v[i]);
  int k;
  scanf("%d", &k);
  rep(i, 0, k) {
    int cnt, p;
    cur.clear();
    scanf("%d", &cnt);
    while (cnt--) {
      scanf("%d", &p);
      cur.insert(p);
    }
    bool ans = true;
    rep(i, 0, m) {
      if (!cur.count(u[i]) && !cur.count(v[i])) {
        ans = false;
        break;
      }
    }
    puts(ans ? "YES" : "NO");
  }
}
