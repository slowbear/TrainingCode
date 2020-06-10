#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int MAX_N = 201000;

long long cnt[2];

long long calc(long long ans) {
  long long l = 0, r = 1e6;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (mid * (mid - 1) / 2 <= ans)
      l = mid;
    else
      r = mid;
  }
  return l;
}

int ans[MAX_N];

int main() {
  long long a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  cnt[0] = calc(a);
  cnt[1] = calc(d);
  if ((cnt[0] > 1) && (cnt[0] * (cnt[0] - 1) / 2) != a) {
    printf("impossible\n");
    return 0;
  }
  if ((cnt[1] > 1) && (cnt[1] * (cnt[1] - 1) / 2) != d) {
    printf("impossible\n");
    return 0;
  }
  if (b + c == 0) {
    if (cnt[1] == 1) {
      for (int i = 0; i < cnt[0]; ++i) printf("0");
      printf("\n");
      return 0;
    } else if (cnt[0] == 1) {
      for (int i = 0; i < cnt[1]; ++i) printf("1");
      printf("\n");
      return 0;
    }
  } else if (b + c != cnt[0] * cnt[1]) {
    printf("impossible\n");
    return 0;
  }
  long long top = cnt[0] + cnt[1];
  for (int i = 1; i <= cnt[0]; ++i) ans[i] = i;
  for (int i = cnt[0]; (i > 0) && c; --i) {
    long long delta = min(top - ans[i], c);
    ans[i] += delta;
    c -= delta;
    if (ans[i] == top) --top;
  }
  int cur = 1;
  for (int i = 1; i <= cnt[0] + cnt[1]; ++i) {
    if (ans[cur] == i) {
      printf("0");
      ++cur;
    } else {
      printf("1");
    }
  }
  printf("\n");
}
