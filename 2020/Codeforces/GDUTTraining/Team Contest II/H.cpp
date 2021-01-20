#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 301000;

int a[MAX_N], b[MAX_N], n;

long long calc() {
  long long ans = 0, ind = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      while (!b[ind]) ++ind;
      ans += abs(i - ind);
      ++ind;
    }
  }
  return ans;
}

int main() {
  int atag = -1, btag = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if ((n & 1) && (a[i] == n / 2 + 1)) atag = i;
    if (a[i] <= n / 2)
      a[i] = 1;
    else
      a[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    if ((n & 1) && (b[i] == n / 2 + 1)) btag = i;
    if (b[i] > (n + 1) / 2)
      b[i] = 1;
    else
      b[i] = 0;
  }
  long long ans = calc();
  if (n & 1) {
    a[atag] = 1;
    b[btag] = 1;
    ans = min(ans, calc());
  }
  printf("%lld\n", ans);
}
