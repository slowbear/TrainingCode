#include <bits/extc++.h>
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

int main() {
  int a, b, c0 = 0, x;
  scanf("%d%d", &a, &b);
  rep(i, 0, 3) {
    scanf("%d", &x);
    if (!x) ++c0;
  }
  if (a > b && c0)
    printf("The winner is a: %d + %d\n", a, c0);
  else
    printf("The winner is b: %d + %d\n", b, c0 ^ 3);
}
