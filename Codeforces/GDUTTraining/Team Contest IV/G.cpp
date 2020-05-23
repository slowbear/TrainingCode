#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_NODES = 3001000;

constexpr int MAX_N = 501000;

int query[MAX_N];

bool is_query[MAX_N];

int gh[MAX_N], gv[MAX_N], gn[MAX_N], total;

int val[MAX_N];

int rt[MAX_N];

int find_rt(int x) { return x == rt[x] ? x : rt[x] = find_rt(rt[x]); }

void join(int u, int v) { rt[find_rt(v)] = rt[find_rt(u)]; }

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

bool done_init[MAX_N];

int calc[MAX_N][20], grand[MAX_N][20];

int depth[MAX_N];

int step_in[MAX_N], step_out[MAX_N], time_step;

void dfs(int u, int fa, int dep) {
  depth[u] = dep;
  calc[u][0] = val[u];
  grand[u][0] = fa;
  step_in[u] = time_step++;
  for (int i = 1; i < 20; ++i) {
    grand[u][i] = grand[grand[u][i - 1]][i - 1];
    calc[u][i] = min(calc[u][i - 1], calc[grand[u][i - 1]][i - 1]);
  }
  for (int i = gh[u]; i != -1; i = gn[i]) {
    int v = gv[i];
    dfs(v, u, dep + 1);
  }
  step_out[u] = time_step;
}

int seg_init[MAX_N];

struct Node {
  int l, r, val, lc, rc, lazy;
  Node() = default;
  Node(int l, int r, int val) : l(l), r(r), val(val), lc(-1), rc(-1), lazy(0) {}
} node[MAX_NODES];

int used = 0;

int build_tree(int l, int r) {
  int u = used++;
  int mid = (l + r) / 2;
  if (l + 1 < r) {
    node[u] = Node(l, r, 0);
    node[u].lc = build_tree(l, mid);
    node[u].rc = build_tree(mid, r);
  } else {
    node[u] = Node(l, r, seg_init[l]);
  }
  return u;
}

inline void update(int root, int new_lazy) {
  if (!node[root].lazy)
    node[root].lazy = new_lazy;
  else if (depth[new_lazy] > depth[node[root].lazy])
    node[root].lazy = new_lazy;
}

void pushdown(int root) {
  if (node[root].l + 1 < node[root].r) {
    update(node[root].lc, node[root].lazy);
    update(node[root].rc, node[root].lazy);
    node[root].lazy = 0;
  } else {
    if (depth[node[root].lazy] > depth[node[root].val])
      node[root].val = node[root].lazy;
  }
}

int get_rt(int root, int index) {
  while (node[root].l + 1 < node[root].r) {
    int mid = (node[root].l + node[root].r) / 2;
    pushdown(root);
    if (index < mid)
      root = node[root].lc;
    else
      root = node[root].rc;
  }
  pushdown(root);
  return node[root].val;
}

void change(int root, int l, int r, int new_lazy) {
  pushdown(root);
  if ((l <= node[root].l) && (r >= node[root].r)) {
    update(root, new_lazy);
  } else {
    int mid = (node[root].l + node[root].r) / 2;
    if (l < mid) change(node[root].lc, l, r, new_lazy);
    if (r > mid) change(node[root].rc, l, r, new_lazy);
  }
}

int log2[MAX_N];

inline int lowbit(int x) { return x & (-x); }

vector<int> vec_ans;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  log2[1] = 0;
  for (int i = 2; i < MAX_N; ++i) log2[i] = log2[i / 2] + 1;
  total = 0;
  memset(gh, -1, sizeof(gh));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &val[i]);
    rt[i] = i;
  }
  memset(is_query, 0, sizeof(is_query));
  for (int i = 0; i < m; ++i) {
    char order;
    scanf(" %c", &order);
    if (order == '+') {
      int u, v;
      scanf("%d%d", &u, &v);
      query[i] = v;
      join(u, v);
      add(u, v);
    } else {
      int u;
      scanf("%d", &u);
      is_query[i] = true;
      query[i] = u;
    }
  }
  memset(done_init, 0, sizeof(done_init));
  time_step = 0;
  for (int i = 1; i <= n; ++i) {
    int u = find_rt(i);
    if (!done_init[u]) {
      dfs(u, u, 0);
      done_init[u] = true;
    }
  }
  for (int i = 1; i <= n; ++i) seg_init[step_in[i]] = find_rt(i);
  int root = build_tree(0, n);
  for (int i = m - 1; i >= 0; --i) {
    if (is_query[i]) {
      int u = query[i];
      int f = get_rt(root, step_in[u]);
      int dis = depth[u] - depth[f] + 1;
      int ans = val[u];
      while (dis) {
        ans = min(ans, calc[u][log2[lowbit(dis)]]);
        u = grand[u][log2[lowbit(dis)]];
        dis ^= lowbit(dis);
      }
      vec_ans.push_back(ans);
    } else {
      int u = query[i];
      change(root, step_in[u], step_out[u], u);
    }
  }
  for (auto it = vec_ans.rbegin(); it != vec_ans.rend(); ++it)
    printf("%d\n", *it);
}
