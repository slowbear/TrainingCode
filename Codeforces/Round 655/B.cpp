#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    bool done = false;
    for (int i = 2; !done && (1LL * i * i <= n); ++i) {
      if (n % i == 0) {
        done = true;
        int a = min(n / i, n - n / i), b = max(n / i, n - n / i);
        printf("%d %d\n", a, b);
      }
    }
    if (!done) printf("%d %d\n", 1, n - 1);
  }
}
