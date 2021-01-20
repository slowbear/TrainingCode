#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

char str[110][1010];

int main() {
  int T;
  scanf("%d", &T);
  memset(str, 0, sizeof(str));
  while (T--) {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) scanf(" %c", &str[i][j]);
    }
    if (y > 2 * x) y = 2 * x;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((str[i][j] == '.') && (str[i][j + 1] == '.')) {
          str[i][j] = '*';
          str[i][j + 1] = '*';
          ans += y;
        }
        if (str[i][j] == '.') {
          str[i][j] = '*';
          ans += x;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
