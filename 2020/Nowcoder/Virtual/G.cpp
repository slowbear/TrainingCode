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

int ch[maxn][2], val[maxn], rnd[maxn], sz[maxn], total;

mt19937 gen(random_device{}());

int new_node(int key) {
  int u = total++;
  ch[u][0] = ch[u][1] = 0;
  sz[u] = 1;
  val[u] = key;
  rnd[u] = gen();
  return u;
}

inline void update(int rt) { sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + 1; }

pair<int, int> split(int rt, int delta, int key) {
  if (!rt) return mp(0, 0);
  int rnk = sz[ch[rt][0]] + 1 + delta;
  if (rnk < key) {
    auto u = split(ch[rt][1], rnk, key);
    ch[rt][1] = u.first;
    update(rt);
    return mp(rt, u.second);
  } else {
    auto u = split(ch[rt][0], delta, key);
    ch[rt][0] = u.second;
    update(rt);
    return mp(u.first, rt);
  }
}

int join(int u, int v) {
  if (!u || !v) return u | v;
  if (rnd[u] > rnd[v]) {
    ch[u][1] = join(ch[u][1], v);
    update(u);
    return u;
  } else {
    ch[v][0] = join(u, ch[v][0]);
    update(v);
    return v;
  }
}

void init() {
  ch[0][0] = ch[0][1] = sz[0] = 0;
  total = 1;
}

void print(int rt) {
  if (rt) {
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
    r += l;
    auto x = split(rt, 0, r);
    auto y = split(x.first, 0, l);
    rt = join(join(y.second, y.first), x.second);
  }
  print(rt);
  printf("\n");
}
