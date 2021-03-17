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

constexpr int maxn = 1e4 + 7;

vector<int> vec[maxn], id;

int cnt[maxn];

int main() {
  int n, mx = 0;
  scanf("%d", &n);
  rep(i, 0, n) {
    scanf("%d", &cnt[i]);
    if (cnt[i] > mx) mx = cnt[i];
  }
  int cur = 1, last_print = -1;
  while (mx--) {
    id.clear();
    rep(i, 0, n) if (cnt[i]) {
      id.pb(i);
      --cnt[i];
    }
    if (id.size() > 1) {
      rep(i, 0, 10) for (int u : id) vec[u].pb(cur++);
      last_print = id[id.size() - 1];
    } else {
      if (id[0] == last_print) ++cur;
      rep(i, 0, 10) {
        vec[id[0]].pb(cur);
        cur += 2;
      }
    }
  }
  rep(i, 0, n) {
    printf("#%d\n", i + 1);
    rep(j, 0, SZ(vec[i])) printf("%d%c", vec[i][j], " \n"[j % 10 == 9]);
  }
}
