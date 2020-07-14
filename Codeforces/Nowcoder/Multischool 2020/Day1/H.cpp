#include <bits/stdc++.h>

using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define SZ(V) (V.size())

constexpr int maxn = 210;

struct Edge {
  int u, v, w, cap;
} e[maxn];
int gh[maxn], gn[maxn], total;

void add(int u, int v, int w, int cap) {
  e[total] = {u, v, w, cap};
  gn[total] = gh[u];
  gh[u] = total++;
}

int d[maxn], pre[maxn];
bool inq[maxn];

int spfa(int s, int t) {
  queue<int> que;
  que.push(s);
  mem(d, 0x3f);
  mem(inq, 0);
  d[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    gre(i, u) {
      int v = e[i].v;
      if (e[i].cap && d[v] > d[u] + e[i].w) {
        d[v] = d[u] + e[i].w;
        pre[v] = i;
        if (!inq[v]) que.push(v), inq[v] = true;
      }
    }
    inq[u] = false;
  }
  return d[t];
}

int n, m;

void augment(int s, int t) {
  while (s != t) {
    int i = pre[s];
    e[i].cap -= 1;
    e[i ^ 1].cap += 1;
    s = e[i].u;
  }
}

VI w, prefix;

void solve() {
  int cost;
  w.clear();
  w.push_back(0);
  while ((cost = spfa(1, n)) != 0x3f3f3f3f) {
    augment(n, 1);
    w.push_back(cost);
  }
  prefix = w;
  rep(i, 1, SZ(w)) prefix[i] += prefix[i - 1];
}

int main() {
#ifdef _VSC_DEBUG
  freopen("input.in", "r", stdin);
#endif
  while (scanf("%d%d", &n, &m) == 2) {
    total = 0;
    mem(gh, -1);
    rep(i, 0, m) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      add(a, b, c, 1);
      add(b, a, -c, 0);
    }
    solve();
    int q;
    scanf("%d", &q);
    rep(i, 0, q) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (1LL * u * (SZ(w) - 1) < v) {
        printf("NaN\n");
      } else {
        int k = v / u;
        LL x = 1LL * u * prefix[k] + 1LL * w[k + 1] * (v - 1LL * k * u), y = v;
        LL g = __gcd(x, y);
        x /= g;
        y /= g;
        printf("%lld/%lld\n", x, y);
      }
    }
  }
}
