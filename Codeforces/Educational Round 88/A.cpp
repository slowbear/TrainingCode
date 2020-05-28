#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a = min(m, n / k);
    m -= a;
    int b = (m + k - 2) / (k - 1);
    printf("%d\n", a - b);
  }
}
