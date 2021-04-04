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

char str[100];

deque<Pii> cur;

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    int n;
    scanf("%d", &n);
    printf("Case #%d:\n", index);
    while (!cur.empty()) cur.pop_back();
    int total = 0;
    bool flag = true;
    while (n--) {
      scanf(" %s", str);
      if (str[2] == 'S') {
        int num;
        scanf("%d", &num);
        if ((num != 0) && (num != 1)) continue;
        ++total;
        if (flag) {
          if (cur.empty() || (cur.back().second != num)) {
            cur.push_back(mp(1, num));
          } else {
            auto fix = cur.back();
            cur.pop_back();
            cur.push_back(mp(fix.first + 1, fix.second));
          }
        } else {
          if (cur.empty() || (cur.front().second != num)) {
            cur.push_front(mp(1, num));
          } else {
            auto fix = cur.front();
            cur.pop_front();
            cur.push_front(mp(fix.first + 1, fix.second));
          }
        }
      } else if (str[2] == 'P') {
        --total;
        if (flag) {
          auto x = cur.back();
          cur.pop_back();
          if (x.first > 1) cur.push_back(mp(x.first - 1, x.second));
        } else {
          auto x = cur.front();
          cur.pop_front();
          if (x.first > 1) cur.push_front(mp(x.first - 1, x.second));
        }
      } else if (str[2] == 'V') {
        flag = !flag;
      } else if (str[2] == 'E') {
        if (total) {
          auto x = flag ? cur.front() : cur.back();
          if (!x.second)
            printf("%d\n", total == 1 ? 0 : 1);
          else {
            int calc = x.first & 1;
            if (total > x.first + 1) calc ^= 1;
            printf("%d\n", calc);
          }
        } else {
          printf("Invalid.\n");
        }
      }
      // printf("****\n");
      // for (auto x : cur) {
      //   printf("%d %d\n", x.first, x.second);
      // }
      // printf("****\n\n");
    }
  }
}
