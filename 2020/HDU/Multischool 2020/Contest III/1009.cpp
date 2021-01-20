#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define SZ(V) (int)(V.size())
#define mp make_pair
constexpr int maxn = 501000;

char str[maxn];

int star[maxn], first, last;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %s", str);
    int len = strlen(str), cur = 0;
    bool chk = true;
    first = last = 0;
    rep(i, 0, len) {
      if (str[i] == '*') star[last++] = i;
      if (str[i] == '(') ++cur;
      if (str[i] == ')') {
        if (cur) {
          --cur;
        } else if (last != first) {
          str[star[first++]] = '(';
        } else {
          chk = false;
          break;
        }
      }
    }
    if (!chk) {
      printf("No solution!\n");
      continue;
    }
    cur = 0;
    first = last = 0;
    per(i, len - 1, -1) {
      if (str[i] == '*') star[last++] = i;
      if (str[i] == ')') ++cur;
      if (str[i] == '(') {
        if (cur) {
          --cur;
        } else if (last != first) {
          str[star[first++]] = ')';
        } else {
          chk = false;
          break;
        }
      }
    }
    if (!chk) {
      printf("No solution!\n");
      continue;
    }
    rep(i, 0, len) if (str[i] != '*') putchar(str[i]);
    printf("\n");
  }
}
