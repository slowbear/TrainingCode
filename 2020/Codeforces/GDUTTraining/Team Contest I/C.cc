#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int maxn = 201000;

int gh[maxn], gn[maxn], gv[maxn], gw[maxn], total;

void add(int u, int v, int w) {
  gv[total] = v;
  gw[total] = w;
  gn[total] = gh[u];
  gh[u] = total++;
}

long long cnt;

long long f[maxn][2];

void dfs(int u, int fa, int mask) {
  f[u][0] = 1;
  f[u][1] = 0;
  for (int i = gh[u]; i != -1; i = gn[i]) {
    int v = gv[i];
    if (v == fa) continue;
    dfs(v, u, mask);
    if (gw[i] & mask) {
      f[u][0] += f[v][1];
      f[u][1] += f[v][0];
    } else {
      f[u][0] += f[v][0];
      f[u][1] += f[v][1];
    }
  }
  cnt += f[u][1];
  long long tmp = 0;
  for (int i = gh[u]; i != -1; i = gn[i]) {
    int v = gv[i];
    if (v == fa) continue;
    if (gw[i] & mask) {
      tmp += (f[u][0] - 1 - f[v][1]) * f[v][0];
      tmp += (f[u][1] - f[v][0]) * f[v][1];
    } else {
      tmp += (f[u][1] - f[v][1]) * f[v][0];
      tmp += (f[u][0] - 1 - f[v][0]) * f[v][1];
    }
  }
  cnt += tmp >> 1;
}

int main() {
  int n;
  scanf("%d", &n);
  memset(gh, -1, sizeof(gh));
  total = 0;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  long long ans = 0;
  for (int i = 0; i < 31; ++i) {
    int mask = 1 << i;
    cnt = 0;
    dfs(1, 1, mask);
    ans += 1LL * mask * cnt;
  }
  printf("%lld\n", ans);
}
