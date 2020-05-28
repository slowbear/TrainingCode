#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

constexpr int MAX_N = 101000;

int gh[MAX_N], gn[MAX_N], gv[MAX_N], total;

void add(int u, int v) {
  gv[total] = v;
  gn[total] = gh[u];
  gh[u] = total++;
}

void dfs(int u, int fa) {}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(gh, -1, sizeof(gh));
  total = 0;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs(1, 1);
}
