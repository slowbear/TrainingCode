#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int MAX_N = 1000;

int d[MAX_N];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0, cnt = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    ++cnt;
    sum += d[i];
    if (cnt * d[i] - sum >= 20) {
      sum = d[i];
      cnt = 1;
      ++ans;
    }
  }
  if (sum) ++ans;
  printf("%d\n", ans);
}
