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

constexpr int maxn = 10100;

LL s[maxn], times[maxn];

inline int lowbit(int x) { return x & (-x); }

LL query(int id) {
  LL ret = 0;
  while (id) {
    ret += times[id];
    id ^= lowbit(id);
  }
  return ret;
}

void real_add(int id, LL val, int rt) {
  while (id <= rt) {
    times[id] += val;
    id += lowbit(id);
  }
}

void add(int id, LL val, int rt) {
  real_add(id, val, rt);
  real_add(id + 1, -val, rt);
}

void range_add_one(int l, int r, LL &ans, int rt) {
  if (r > rt) {
    ans += r - rt;
    r = rt;
  }
  real_add(l, 1, rt);
  real_add(r + 1, -1, rt);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 1, n + 1) scanf("%lld", &s[i]);
    rep(i, 1, n + 2) times[i] = 0;
    LL ans = 0;
    rep(i, 1, n + 1) {
      add(i, max(s[i] - 1 - query(i), 0LL), n + 1);
      LL rest = max(query(i) - s[i] + 1, 0LL);
      add(i + 1, rest, n + 1);
      add(i, -rest, n + 1);
      range_add_one(i + s[i] - query(i) + 1, i + s[i], ans, n + 1);
    }
    ans += query(n + 1);
    printf("%lld\n", ans);
  }
}
