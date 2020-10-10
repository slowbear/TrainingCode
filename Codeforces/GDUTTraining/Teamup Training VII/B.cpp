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

int w[maxn], d[maxn];

priority_queue<Pll, vector<Pll>, greater<Pll>> q1, q2;

vector<long long> v1, v2;

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int L, n, m;
    scanf("%d%d%d", &L, &n, &m);
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    v1.clear();
    v2.clear();
    rep(i, 0, n) {
      scanf("%d", &w[i]);
      q1.push(mp(w[i], w[i]));
    }
    rep(i, 0, m) {
      scanf("%d", &d[i]);
      q2.push(mp(d[i], d[i]));
    }
    rep(i, 0, L) {
      auto c1 = q1.top();
      v1.pb(c1.first);
      q1.pop();
      q1.push(mp(c1.first + c1.second, c1.second));
      auto c2 = q2.top();
      v2.pb(c2.first);
      q2.pop();
      q2.push(mp(c2.first + c2.second, c2.second));
    }
    reverse(v2.begin(), v2.end());
    LL ans = 0;
    rep(i, 0, L) if (v1[i] + v2[i] > ans) ans = v1[i] + v2[i];
    printf("Case #%d: %lld\n", ind, ans);
  }
}
