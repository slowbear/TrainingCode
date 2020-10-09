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

constexpr int maxn = 201000;

char str[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf(" %s", str);
    int ans = 0;
    bool flag = false;
    rep(i, 0, n) {
      if (!strncmp(str + i, "CCPC", 4)) ++ans;
      flag = flag || !strncmp(str + i, "CCPP", 4) || !strncmp(str + i, "PCPC", 4) ||
             (!strncmp(str + i, "CCC", 3) && strncmp(str + i, "CCCPC", 5));
    }
    flag = flag || !strncmp(str, "CPC", 3) || !strncmp(str + n - 3, "CCP", 3) ||
           !strncmp(str + n - 3, "CCC", 3);
    if (flag) ++ans;
    printf("%d\n", ans);
  }
}
