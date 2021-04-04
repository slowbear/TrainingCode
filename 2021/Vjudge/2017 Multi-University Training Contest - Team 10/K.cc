#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using PLi = pair<LL, int>;
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

constexpr int maxn = 1e5 + 5;
vector<pair<int, int>> v[maxn];
int T, n, m;
bool vis[maxn];
LL d1[maxn], d2[maxn], d3[maxn];

void init() {
  for (int i = 1; i <= n; i++) {
    v[i].clear();
    d1[i] = d2[i] = d3[i] = LONG_LONG_MAX;
  }
}

void dij(int s) {
  priority_queue<PLi, vector<PLi>, greater<PLi>> pq;
  for (int i = 1; i <= n; i++) vis[i] = false;
  d1[s] = 0;
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    PLi tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (vis[u]) continue;
    vis[u] = true;

    for (auto e : v[u]) {
      int nxt = e.first, w = e.second;
      LL val = d1[u] + w;
      if (vis[nxt]) continue;
      if (d1[nxt] >= val) {
        d2[nxt] = d1[nxt];
        d1[nxt] = val;
        pq.push(make_pair(d1[nxt], nxt));
      } else if (d2[nxt] > val) {
        d2[nxt] = val;
      }
      if (d2[u] + w < d2[nxt]) {
        d2[nxt] = d2[u] + w;
      }
    }
  }
}

void dij2(int s, LL d[]) {
  priority_queue<PLi, vector<PLi>, greater<PLi>> pq;
  for (int i = 1; i <= n; i++) vis[i] = false;
  d[s] = 0;
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    PLi tmp = pq.top();
    pq.pop();
    int u = tmp.second;
    if (vis[u]) continue;
    vis[u] = true;

    for (auto e : v[u]) {
      int nxt = e.first, w = e.second;
      if (!vis[nxt] && d[nxt] > d[u] + w) {
        d[nxt] = d[u] + w;
        pq.push(make_pair(d[nxt], nxt));
      }
    }
  }
}

void Update(LL val, LL &Min, LL &SeMin) {
  if (val < Min) {
    SeMin = Min;
    Min = val;
  } else if (val < SeMin) {
    SeMin = val;
  }
  return;
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 1; i <= m; i++) {
      int a, b, w;
      scanf("%d %d %d", &a, &b, &w);
      v[a].push_back(Pii(b, w));
      v[b].push_back(Pii(a, w));
    }

    dij(1);
    dij2(n, d3);

    LL Min = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
      LL minw = LONG_LONG_MAX;
      for (auto e : v[i]) {
        LL w = e.second;
        minw = min(minw, w);
      }
      Min = min(Min, d1[i] + d3[i] + 2LL * minw);
    }
    printf("%lld\n", min(Min, d2[n]));
  }
}
