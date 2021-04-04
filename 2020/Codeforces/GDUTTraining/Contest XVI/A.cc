#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long f[200][3];

int main() {
  int l, k;
  scanf("%d%d", &l, &k);
  f[0][0] = 0;  // dark thin
  f[0][1] = 0;  // dark thick
  f[0][2] = 1;  // white thin
  for (int i = 1; i <= l; ++i) {
    f[i][0] = f[i - 1][2];
    if (i >= k)
      f[i][1] = f[i - k][2];
    else
      f[i][1] = 0;
    f[i][2] = f[i - 1][0] + f[i - 1][1];
  }
  long long ans = 0;
  for (int i = 1; i <= l; ++i) ans += f[i][0] + f[i][1];
  printf("%lld\n", ans);
}
