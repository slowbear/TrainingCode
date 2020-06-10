#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int p = 1000000007;

constexpr int MAX_N = 2600;

long long my_pow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long tmp = my_pow(a, b >> 1, p);
  tmp = tmp * tmp % p;
  if (b & 1) tmp = tmp * a % p;
  return tmp;
}

long long f[MAX_N], g[MAX_N];

long long C[MAX_N][MAX_N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) g[i] = i * my_pow(i - 1, n - 1, p) % p;
  f[1] = 0;
  f[2] = 2;
  for (int i = 0; i < MAX_N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 0; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  }
  for (int i = 3; i <= n; ++i) {
    f[i] = g[i];
    for (int j = 2; j < i; ++j) f[i] = ((f[i] - C[i][j] * f[j]) % p + p) % p;
  }
  printf("%lld\n", f[k]);
}
