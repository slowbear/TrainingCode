#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

constexpr int MAX_N = 100;

long long f[MAX_N];

int main() {
  int T;
  scanf("%d", &T);
  f[0] = 1;
  for (int i = 1; i < 30; ++i) f[i] = f[i - 1] * ((i & 1) ? 9 : 2);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    int cur = 0;
    while (n >= f[cur + 1]) ++cur;
    if (cur & 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
