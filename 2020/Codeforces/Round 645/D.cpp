#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 401000;

long long d[MAX_N], prefix[MAX_N], val[MAX_N], prefix_val[MAX_N];

int main() {
  int n;
  long long x;
  scanf("%d%lld", &n, &x);
  d[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
    val[i] = d[i] * (d[i] + 1) / 2;
  }
  for (int i = n + 1; i <= 2 * n; ++i) {
    d[i] = d[i - n];
    val[i] = val[i - n];
  }
  prefix[0] = 0;
  prefix_val[0] = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    prefix[i] = prefix[i - 1] + d[i];
    prefix_val[i] = prefix_val[i - 1] + val[i];
  }
  long long ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    auto it = lower_bound(prefix, prefix + i + 1, prefix[i] - x);
    long long tmp = prefix_val[i] - prefix_val[it - prefix],
              y = x - (prefix[i] - prefix[it - prefix]);
    if (y) {
      long long l = max(1LL, d[it - prefix] - y + 1), r = d[it - prefix];
      tmp += (r - l + 1) * (l + r) / 2;
    }
    if (tmp > ans) ans = tmp;
  }
  printf("%lld\n", ans);
}
