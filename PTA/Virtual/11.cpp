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

int a[100], b[100];

int gh[1000], gn[1000], gv[1000], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int build(int a[], int b[], int sz) {
  int pos;
  rep(i, 0, sz) if (b[i] == a[0]) pos = i;
  if (sz != 1) {
    add(a[0], build(a + 1, b, pos));
    add(a[0], build(a + pos + 1, b + pos + 1, sz - pos - 1));
  }
  return a[0];
}

void bfs(int s) {
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    printf(u == s ? "%d" : " %d", u);
    grep(i, u) {
      int v = gv[i];
      que.push(v);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &a[i]);
  rep(i, 0, n) scanf("%d", &b[i]);
  mem(gh, -1);
  total = 0;
  int r = build(a, b, n);
  bfs(r);
}
