// @WiLe
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

const int MAXN = 2e5 + 5;

map<Pii, int> last;
int ans[MAXN], sum[MAXN];
vector<int> ex[MAXN];

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 1; i <= s; i++) {
    int op, x, y;
    scanf("%d", &op);
    scanf("%d %d", &x, &y);
    if (op == 1) {
      last[Pii(x, y)] = sum[y];
      ex[x].pb(y);
    } else if (op == 2) {
      ans[x] += sum[y] - last[Pii(x, y)];
      // if (x == 1) cout << i << " " << sum[y] << " " << ans[x] << endl;
      last[Pii(x, y)] = -1;
    } else {
      sum[y]++;
      ans[x]--;
      // if (x == 1) cout << -1 << " " << ans[x] << endl;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (auto it : ex[i]) {
      int tmp = last[Pii(i, it)];
      if (tmp == -1) continue;
      ans[i] += sum[it] - tmp;
      // if (i == 1) cout << sum[it] << " " << ans[i] << endl;
      last[Pii(i, it)] = -1;
    }
    printf("%d\n", ans[i]);
  }

  return 0;
}
