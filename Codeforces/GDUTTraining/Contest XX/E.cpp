#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 1 << 19;

vector<int> query_list[MAX_N];

int query[MAX_N], ans[MAX_N];

int gh[MAX_N], gn[MAX_N], gv[MAX_N], total;

void gadd(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

int arr[MAX_N];

inline int lowbit(int x) { return x & (-x); }

void add(int key, int val) {
  while (key < MAX_N) {
    arr[key] += val;
    key += lowbit(key);
  }
}

int sz[MAX_N];

void initial_dfs(int u, int fa) {
  sz[u] = 1;
  for (int i = gh[u]; i != -1; i = gn[i]) {
    int v = gv[i];
    if (v != fa) {
      initial_dfs(v, u);
      sz[u] += sz[v];
    }
  }
  add(sz[u], 1);
}

int get(int key) {
  int cur = 0, ans = 0, step = 1 << 18;
  while (step && (cur < key)) {
    if (cur + arr[ans + step] < key) {
      ans += step;
      cur += arr[ans];
    }
    step >>= 1;
  }
  return ans + 1;
}

void calc_dfs(int u, int fa) {
  if (u != fa) {
    int tmp = sz[u];
    sz[u] = sz[fa];
    sz[fa] = sz[u] - tmp;
    add(tmp, -1);
    add(sz[fa], 1);
  }
  for (int index : query_list[u]) ans[index] = get(query[index]);
  for (int i = gh[u]; i != -1; i = gn[i]) {
    int v = gv[i];
    if (v != fa) calc_dfs(v, u);
  }
  if (u != fa) {
    int tmp = sz[fa];
    sz[fa] = sz[u];
    sz[u] = sz[fa] - tmp;
    add(tmp, -1);
    add(sz[u], 1);
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  total = 0;
  memset(gh, -1, sizeof(gh));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    gadd(u, v);
    gadd(v, u);
  }
  for (int i = 0; i < q; ++i) {
    int u;
    scanf("%d%d", &u, &query[i]);
    query_list[u].push_back(i);
  }
  memset(arr, 0, sizeof(arr));
  memset(sz, 0, sizeof(sz));
  initial_dfs(1, 1);
  calc_dfs(1, 1);
  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
}
