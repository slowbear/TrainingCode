#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int p = 1e9 + 7;

constexpr int maxn = 5001000;

constexpr int n = 5000000;

int ni[maxn];

int C[maxn];

int pow_mod(int a, int b, int p) {
  if (!a) return 0;
  if (!b) return 1;
  int ans = pow_mod(a, b >> 1, p);
  ans = 1LL * ans * ans % p;
  if (b & 1) ans = 1LL * ans * a % p;
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  ni[1] = 1;
  for (int i = 2; i < maxn; ++i) ni[i] = 1LL * ni[p % i] * (p - p / i) % p;
  C[0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i] = 1LL * C[i - 1] * (n - i + 1) % p * ni[i] % p;
  }
  for (int i = n - 1; i >= 0; --i) C[i] = (C[i] + C[i + 1]) % p;
  int x = pow_mod(ni[2], n, p);
  while (T--) {
    int k;
    scanf("%d", &k);
    printf("%lld\n", 1LL * C[k] * x % p);
  }
}
