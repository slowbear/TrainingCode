#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<long long, int> keep;

int n;

long long p;

void dfs(int cur, int end, long long sum, long long base, int state) {
  if (cur == end) {
    keep[sum] = state;
    return;
  }
  dfs(cur + 1, end, (sum + base) % p, base * 10 % p, state);
  dfs(cur + 1, end, (sum + 2 * base) % p, base * 10 % p, state | (1 << cur));
}

int ans[42], last;

bool check_dfs(int cur, int end, long long sum, long long base, long long state) {
  if (cur == end) {
    if (keep.find(p - sum) != keep.end()) {
      state = state | keep[p - sum];
      for (int i = 0; i < n; ++i) {
        ans[last++] = (state & (1LL << i)) ? 2 : 1;
      }
      while (last--) printf("%d", ans[last]);
      printf("\n");
      return true;
    } else {
      return false;
    }
  }
  if (!check_dfs(cur + 1, end, (sum + base) % p, (base * 10) % p, state)) {
    return check_dfs(cur + 1, end, (sum + 2 * base) % p, (base * 10) % p, state | (1LL << cur));
  } else {
    return true;
  }
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("2\n");
    return 0;
  }
  p = 1LL << n;
  keep.clear();
  int bound = min(16, n / 2);
  dfs(0, bound, 0, 1, 0);
  long long x = 1;
  for (int i = 0; i < bound; ++i) x = x * 10 % p;
  if (!check_dfs(bound, n, 0, x, 0)) printf("-1\n");
}
