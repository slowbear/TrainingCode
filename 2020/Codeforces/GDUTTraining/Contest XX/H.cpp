#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int maxn = 101000;

int a[maxn];

int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int mask = 1; mask < (1 << 21); mask <<= 1) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] & mask) ++cnt;
    ans += 1LL * cnt * cnt * cnt * mask;
    if (cnt < n) ans += 3LL * cnt * (n - cnt) * (n - cnt) * mask;
  }
  printf("%lld\n", ans);
}
