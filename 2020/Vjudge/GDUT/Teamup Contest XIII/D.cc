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
  int T;
  scanf("%d", &T);
  const double pi = acos(-1);
  while (T--) {
    double a, b, r, d;
    scanf("%lf%lf%lf%lf", &a, &b, &r, &d);
    double f = atan((a + r) / b);
    double g = min(f + d * pi / 180.0, pi / 2);
    double h = sqrt((a + r) * (a + r) + b * b);
    printf("%.12f\n", h * sin(g) - r);
  }
}
