#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int x = x2 - x1, y = y2 - y1;
    printf("%lld\n", 1LL * x * y + 1);
  }
}
