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

constexpr int maxn = 501000;

int ch[maxn][2], sz[maxn], priv[maxn], total;

int val[maxn], rev[maxn];

mt19937 gen(random_device{}());

void init() {
  ch[0][0] = ch[0][1] = sz[0] = 0;
  total = 1;
}

inline void maintain(int rt) { sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + 1; }

inline void pushdown(int rt) {
  if (rev[rt]) swap(ch[rt][0], ch[rt][1]);
  rev[ch[rt][0]] ^= rev[rt];
  rev[ch[rt][1]] ^= rev[rt];
  rev[rt] = 0;
}

int new_node(int key) {
  int u = total++;
  ch[u][0] = ch[u][1] = 0;
  sz[u] = 1;
  priv[u] = gen();
  val[u] = key;
  rev[u] = 0;
  return u;
}

pair<int, int> split_by_size(int rt, int key) {
  if (!rt) return mp(0, 0);
  pushdown(rt);
  int rnk = sz[ch[rt][0]] + 1;
  if (rnk < key) {
    auto u = split_by_size(ch[rt][1], key - rnk);
    ch[rt][1] = u.first;
    maintain(rt);
    return mp(rt, u.second);
  } else {
    auto u = split_by_size(ch[rt][0], key);
    ch[rt][0] = u.second;
    maintain(rt);
    return mp(u.first, rt);
  }
}

int join(int u, int v) {
  if (!u || !v) return u | v;
  if (priv[u] > priv[v]) {
    pushdown(u);
    ch[u][1] = join(ch[u][1], v);
    maintain(u);
    return u;
  } else {
    pushdown(v);
    ch[v][0] = join(u, ch[v][0]);
    maintain(v);
    return v;
  }
}

void print(int rt) {
  if (rt) {
    pushdown(rt);
    print(ch[rt][0]);
    printf("%d ", val[rt]);
    print(ch[rt][1]);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  init();
  int rt = new_node(1);
  rep(i, 2, n + 1) rt = join(rt, new_node(i));
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    auto u = split_by_size(rt, r + 1);
    auto v = split_by_size(u.first, l);
    rev[v.second] ^= 1;
    rt = join(join(v.first, v.second), u.second);
  }
  print(rt);
  printf("\n");
}
