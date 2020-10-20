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

constexpr int maxn = 20001000;

int ch[maxn][2], sz[maxn], priv[maxn], rev[maxn], total;

LL sum[maxn], val[maxn];

mt19937 gen(random_device{}());

void init() {
  total = 1;
  ch[0][0] = ch[0][1] = sz[0] = val[0] = sum[0] = 0;
}

void maintain(int u) {
  sz[u] = sz[ch[u][0]] + sz[ch[u][1]] + 1;
  sum[u] = sum[ch[u][0]] + sum[ch[u][1]] + val[u];
}

int new_node(int key) {
  int u = total++;
  ch[u][0] = ch[u][1] = rev[u] = 0;
  sz[u] = 1;
  sum[u] = val[u] = key;
  priv[u] = gen();
  return u;
}

int clone(int u) {
  if (!u) return 0;
  int v = total++;
  ch[v][0] = ch[u][0];
  ch[v][1] = ch[u][1];
  sz[v] = sz[u];
  val[v] = val[u];
  sum[v] = sum[u];
  rev[v] = rev[u];
  priv[v] = priv[u];
  return v;
}

void pushdown(int u) {
  if (!rev[u]) return;
  int l = clone(ch[u][0]), r = clone(ch[u][1]);
  if (l) rev[l] ^= 1;
  if (r) rev[r] ^= 1;
  ch[u][0] = r;
  ch[u][1] = l;
  rev[u] = 0;
}

int merge(int u, int v) {
  if (!u || !v) return u | v;
  if (priv[u] < priv[v]) {
    int x = clone(v);
    pushdown(x);
    ch[x][0] = merge(u, ch[x][0]);
    maintain(x);
    return x;
  } else {
    int x = clone(u);
    pushdown(x);
    ch[x][1] = merge(ch[x][1], v);
    maintain(x);
    return x;
  }
}

Pii split_by_size(int u, int rank) {
  if (!u) return mp(0, 0);
  u = clone(u);
  pushdown(u);
  int cur = sz[ch[u][0]] + 1;
  if (cur < rank) {
    auto v = split_by_size(ch[u][1], rank - cur);
    ch[u][1] = v.first;
    maintain(u);
    return mp(u, v.second);
  } else {
    auto v = split_by_size(ch[u][0], rank);
    ch[u][0] = v.second;
    maintain(u);
    return mp(v.first, u);
  }
}

int remove_head(int u) {
  if (!u) return 0;
  u = clone(u);
  pushdown(u);
  if (ch[u][0]) {
    ch[u][0] = remove_head(ch[u][0]);
    maintain(u);
  } else {
    u = ch[u][1];
  }
  return u;
}

void print(int u) {
  if (!u) return;
  u = clone(u);
  pushdown(u);
  if (ch[u][0]) print(ch[u][0]);
  printf("%lld ", val[u]);
  if (ch[u][1]) print(ch[u][1]);
}

VI rt;

int main() {
#ifdef DEBUG
  freopen("P5055_7.in", "r", stdin);
#endif
  init();
  rt.pb(0);
  int n;
  scanf("%d", &n);
  LL last_ans = 0;
  rep(i, 0, n) {
    LL ver, opt;
    scanf("%lld%lld", &ver, &opt);
    if (opt == 1) {
      LL p, x;
      scanf("%lld%lld", &p, &x);
      p ^= last_ans;
      x ^= last_ans;
      auto u = split_by_size(rt[ver], p + 1);
      rt.pb(merge(merge(u.first, new_node(x)), u.second));
    } else if (opt == 2) {
      LL p;
      scanf("%lld", &p);
      p ^= last_ans;
      auto u = split_by_size(rt[ver], p);
      rt.pb(merge(u.first, remove_head(u.second)));
    } else if (opt == 3) {
      LL l, r;
      scanf("%lld%lld", &l, &r);
      l ^= last_ans;
      r ^= last_ans;
      auto x = split_by_size(rt[ver], r + 1);
      auto y = split_by_size(x.first, l);
      int u = clone(y.second);
      rev[u] ^= 1;
      rt.pb(merge(merge(y.first, u), x.second));
    } else if (opt == 4) {
      LL l, r;
      scanf("%lld%lld", &l, &r);
      l ^= last_ans;
      r ^= last_ans;
      rt.pb(rt[ver]);
      auto x = split_by_size(rt[ver], r + 1);
      auto y = split_by_size(x.first, l);
      last_ans = sum[y.second];
      printf("%lld\n", last_ans);
    }
  }
}
