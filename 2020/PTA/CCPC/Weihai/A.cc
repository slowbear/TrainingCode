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
  while (T--) {
    LL n, x, t;
    scanf("%lld%lld%lld", &n, &x, &t);
    LL gap = min(max(0LL, 2LL * t + x - 2LL * n * t), max(0LL, x - 2LL * n * t) + t);
    printf("%lld\n", 4LL * t * n + gap);
  }
}
