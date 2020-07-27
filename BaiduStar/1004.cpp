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

constexpr int maxn = 101000;

bool second[maxn];
int first[maxn], cnt;
int last;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    cnt = 0;
    last = 0;
    mem(second, 0);
    rep(i, 0, n) {
      int id, pos;
      scanf("%d%d", &id, &pos);
      if (id & 1) {
        second[pos] = true;
        if (pos > last) last = pos;
      } else {
        first[cnt++] = pos;
      }
    }
    sort(first, first + cnt, greater<int>());
    int cur = 0;
    while (cur != cnt && !second[first[cur] + 1]) {
      if (first[cur] + 1 > last) last = first[cur] + 1;
      ++cur;
    }
    int ans = last ? last + 1 : 0;
    if (cur != cnt) ans = max(ans, first[cur] + 3);
    printf("%d\n", ans);
  }
}
