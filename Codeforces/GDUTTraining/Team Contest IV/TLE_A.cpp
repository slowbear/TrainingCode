//! Time limit exceeded on test 12
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 51000;

constexpr int MAX_M = 100;

struct Node {
  int l, r, lc, rc, val;
  Node() = default;
  Node(int l, int r) : l(l), r(r), lc(-1), rc(-1), val(0) {}
} node[MAX_N * 1000];

int total;

int init_val[MAX_N];

int rt[MAX_M][MAX_N];

int build(int l, int r) {
  int u = total++;
  node[u] = Node(l, r);
  if (l + 1 < r) {
    int mid = (l & r) + ((l ^ r) >> 1);
    node[u].lc = build(l, mid);
    node[u].rc = build(mid, r);
  }
  return u;
}

int delta_add(int base, int index, int dx) {
  int u = total++;
  node[u] = node[base];
  node[u].val += dx;
  if (node[u].l + 1 < node[u].r) {
    int mid = (node[u].l & node[u].r) + ((node[u].l ^ node[u].r) >> 1);
    if (index < mid)
      node[u].lc = delta_add(node[u].lc, index, dx);
    else
      node[u].rc = delta_add(node[u].rc, index, dx);
  }
  return u;
}

int query(int u, int index) {
  while (node[u].l + 1 < node[u].r) {
    int mid = (node[u].l & node[u].r) + ((node[u].l ^ node[u].r) >> 1);
    if (index < mid)
      u = node[u].lc;
    else
      u = node[u].rc;
  }
  return node[u].val;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  total = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &init_val[i]);
  rt[0][0] = build(0, MAX_N);
  for (int i = 1; i < MAX_M; ++i) rt[i][0] = build(0, i);
  for (int i = 1; i <= n; ++i) {
    rt[0][i] = delta_add(rt[0][i - 1], init_val[i], 1);
    for (int j = 1; j < MAX_M; ++j)
      rt[j][i] = delta_add(rt[j][i - 1], init_val[i] % j, 1);
  }
  while (q--) {
    int l, r, m, x;
    scanf("%d%d%d%d", &l, &r, &x, &m);
    if (m < MAX_M) {
      printf("%d\n", query(rt[m][r], x) - query(rt[m][l - 1], x));
    } else {
      int ans = 0;
      for (int i = x; i < MAX_N; i += m)
        ans += query(rt[0][r], i) - query(rt[0][l - 1], i);
      printf("%d\n", ans);
    }
  }
}
