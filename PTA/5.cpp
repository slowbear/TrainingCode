#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

int num[10], last;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans = a * b;
  last = 0;
  if (!ans) {
    puts("0");
    return 0;
  }
  while (ans) {
    num[last++] = ans % 10;
    ans /= 10;
  }
  int cur = 0;
  while (!num[cur]) ++cur;
  rep(i, cur, last) printf("%d", num[i]);
  printf("\n");
}
