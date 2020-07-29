#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (int)(V.size())

constexpr int maxn = 201000;

char str[maxn];

int cnt[10];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %s", str);
    int len = strlen(str), ans = len;
    mem(cnt, 0);
    rep(i, 0, len)++ cnt[str[i] - '0'];
    rep(i, 0, 10) ans = min(ans, len - cnt[i]);
    rep(i, 0, 10) {
      rep(j, 0, 10) {
        int cnt = 0;
        bool flag = true;
        rep(cur, 0, len) {
          if (flag && (str[cur] - '0' == i)) {
            ++cnt;
            flag = false;
          } else if (!flag && (str[cur] - '0' == j)) {
            ++cnt;
            flag = true;
          }
        }
        if (cnt & 1) --cnt;
        ans = min(ans, len - cnt);
      }
    }
    printf("%d\n", ans);
  }
}