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

constexpr int maxn = 1 << 21;

int cnt[maxn];

int main() {
  int n;
  LL ans = 0;
  scanf("%d", &n);
  int cur = 0;
  cnt[0] = 1;
  rep(i, 0, n) {
    int bit;
    scanf("%d", &bit);
    cur = cur ^ (1 << bit);
    ans += cnt[cur];
    ++cnt[cur];
  }
  printf("%lld\n", ans);
}
