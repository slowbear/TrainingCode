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

const char constexpr *ans[2] = {"Horse", "Rabbit"};

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    LL a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    printf("Case #%d: ", index);
    if (b | c | d) {
      if (a & 1) {
        if (c > 1) {
          puts(ans[b % 3 != 1]);
        } else if (c == 1) {
          puts(ans[b % 3 == 0]);
        } else {
          puts(ans[b % 3 != 2]);
        }
      } else {
        puts(c ? ans[b % 3 != 0] : ans[b % 3 == 2]);
      }
    } else {
      puts(ans[a && (~a & 1)]);
    }
  }
}
