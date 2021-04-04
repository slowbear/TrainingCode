#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long a, b;

vector<int> ans;

int main() {
  scanf("%lld%lld", &a, &b);
  b = 1LL << b;
  while (a < b) {
    if ((a << 1) <= b) {
      ans.push_back(0);
      if ((a << 1) == b) break;
      a <<= 1;
    } else {
      ans.push_back(1);
      a = b - a;
    }
  }
  for (auto it = ans.rbegin(); it != ans.rend(); ++it) printf("%d", *it);
  printf("\n");
}
