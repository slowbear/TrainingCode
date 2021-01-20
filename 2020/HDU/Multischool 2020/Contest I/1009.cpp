#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<long long, long long> Pll;
typedef Pll TimeStep;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define VS stack<pair<int, TimeStep>>
#define SZ(V) (int)(V.size())
#define mp make_pair

const int maxn = 101000;
Pll node[maxn];

bool compare(const Pll &x, const Pll &y) {
  if (x.second == y.second) return x.first > y.first;
  return x.second > y.second;
}

bool operator<=(const TimeStep &x, const TimeStep &y) {
  return x.first * y.second <= y.first * x.second;
}

VS ans;

TimeStep calc(LL u, LL v) {
  return mp(node[u].first - node[v].first, node[v].second - node[u].second);
}

bool flag[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld%lld", &node[i].first, &node[i].second);
    rep(i, 0, n) flag[i] = true;
    sort(node, node + n, compare);
    ans.push(mp(0, mp(3000000000LL, 1)));
    rep(i, 1, n) {
      int u = ans.top().first;
      if (node[i] == node[u]) flag[u] = false;
      if (node[i].first <= node[u].first) continue;
      while (ans.top().second <= calc(i, ans.top().first)) ans.pop();
      ans.push(mp(i, calc(i, ans.top().first)));
    }
    int cnt = 0;
    while (!ans.empty()) {
      int u = ans.top().first;
      ans.pop();
      if (flag[u]) ++cnt;
    }
    printf("%d\n", cnt);
  }
}
