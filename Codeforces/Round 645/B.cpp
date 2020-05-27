#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 101000;

int a[MAX_N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      ++cur;
      if (ans + cur > a[i]) {
        ans += cur;
        cur = 0;
      }
    }
    printf("%d\n", ans);
  }
}
