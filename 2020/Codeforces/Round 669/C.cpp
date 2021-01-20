#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pii = pair<int, int>;
using VI = vector<int>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 101000;

int p[maxn];

int main() {
  int n;
  scanf("%d", &n);
  int cur = 1, sum = n * (n + 1) >> 1;
  rep(i, 2, n + 1) {
    int a, b;
    printf("? %d %d\n", i, cur);
    fflush(stdout);
    scanf("%d", &a);
    printf("? %d %d\n", cur, i);
    fflush(stdout);
    scanf("%d", &b);
    if (a > b) {
      p[i] = a;
      sum -= a;
    } else {
      p[cur] = b;
      sum -= b;
      cur = i;
    }
  }
  p[cur] = sum;
  printf("!");
  rep(i, 1, n + 1) printf(" %d", p[i]);
  printf("\n");
  fflush(stdout);
}
