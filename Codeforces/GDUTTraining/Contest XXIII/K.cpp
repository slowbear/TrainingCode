#error unfinished
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int p = 1000000007;

long long my_pow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long tmp = my_pow(a, b >> 1, p);
  tmp = tmp * tmp % p;
  if (b & 1) tmp = tmp * a % p;
  return tmp;
}

long long f[3000];

long long C[3000], ni[3000];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) f[i] = i * my_pow(i - 1, n - 1, p) % p;
  long long ans = f[k];
  C[1] = k;
  ni[1] = 1;
  for (int i = 2; i < n; ++i) ni[i] = (p - p / i) * ni[p % i] % p;
  for (int i = 2; i <= k; ++i) C[i] = C[i - 1] * (k - i + 1) % p * ni[i] % p;
  for (int i = 3; i <= k; ++i) f[i] = ((f[i] - i * f[i - 1]) % p + p) % p;
  // for (int i = 2; i < k; ++i) {
  //   ans = ((ans - C[i] * f[i]) % p + p) % p;
  // }
  printf("%lld\n", f[k]);
}
