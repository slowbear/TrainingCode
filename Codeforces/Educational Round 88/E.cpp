#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

constexpr int p = 998244353;

constexpr int MAX_N = 501000;

int ni[MAX_N];

long long C[MAX_N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  ni[1] = 1;
  for (int i = 2; i < MAX_N; ++i) ni[i] = 1LL * (p - p / i) * ni[p % i] % p;
  long long ans = 0;
  memset(C, 0, sizeof(C));
  C[k - 1] = 1;
  for (int i = k; i < n; ++i) C[i] = C[i - 1] * i % p * ni[i - k + 1] % p;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + C[n / i - 1]) % p;
  }
  printf("%lld\n", ans);
}
