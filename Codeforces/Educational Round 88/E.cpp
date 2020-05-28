#error unfinished
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

int f[20][20];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  memset(f, 0, sizeof(f));
  f[0][1] = 1;
}
