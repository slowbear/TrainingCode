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

struct factor {
  LL x, y;
};

factor operator+(const factor &a, const factor &b) {
  LL new_y = a.y * b.y;
  LL new_x = a.x * b.y + b.x * a.y;
  LL d = __gcd(abs(new_x), abs(new_y));
  return factor{new_x / d, new_y / d};
}

int main() {
  int n;
  scanf("%d", &n);
  factor sum{0, 1};
  rep(i, 0, n) {
    LL x, y;
    scanf("%lld/%lld", &x, &y);
    sum = sum + factor{x, y};
  }
  if (!sum.x) {
    printf("0\n");
    return 0;
  }
  LL z = sum.x / sum.y;
  sum.x = sum.x % sum.y;
  if (z) printf("%lld", z);
  if (sum.x) {
    if (z) printf(" ");
    printf("%lld/%lld", sum.x, sum.y);
  }
  printf("\n");
}
