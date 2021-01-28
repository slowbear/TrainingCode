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

constexpr int maxn = 2e3 + 7;

bool flag[maxn];

bool check(int num, int bit) {
  while (num) {
    if (num % 10 == bit) return true;
    num /= 10;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int q, d;
    scanf("%d%d", &q, &d);
    mem(flag, 0);
    rep(i, 0, maxn) {
      flag[i] = check(i, d);
      if (flag[i]) continue;
      rep(j, d, i) {
        flag[i] = flag[j] && flag[i - j];
        if (flag[i]) break;
      }
    }
    while (q--) {
      int num;
      scanf("%d", &num);
      if (num < maxn && !flag[num]) {
        puts("NO");
      } else {
        puts("YES");
      }
    }
  }
}
