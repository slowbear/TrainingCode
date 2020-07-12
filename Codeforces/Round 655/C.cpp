#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int MAX_N = 201000;

int a[MAX_N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, ans = 0, tmp = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == i) {
        if (tmp) {
          tmp = 0;
          ++ans;
        }
      } else {
        ++tmp;
      }
    }
    if (tmp) ++ans;
    if (ans > 2) ans = 2;
    printf("%d\n", ans);
  }
}
