#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

char str[10][100];

int f[100];

bool contain(char *s, char *t) {
  f[0] = f[1] = 0;
  int lens = strlen(s), lent = strlen(t);
  for (int i = 1; i < lent; ++i) {
    int pre = f[i];
    while (pre && (t[i] != t[pre])) pre = f[pre];
    f[i + 1] = t[i] == t[pre] ? pre + 1 : 0;
  }
  int cur = 0;
  for (int i = 0; i < lens; ++i) {
    while (cur && (s[i] != t[cur])) cur = f[cur];
    if (s[i] == t[cur]) ++cur;
    if (cur == lent) return true;
  }
  return false;
}

char ans[100];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, len;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", str[i]);
    ans[0] = '\0';
    len = strlen(str[0]);
    for (int size = 3; size <= len; ++size) {
      for (int i = 0; i + size <= len; ++i) {
        bool flag = true;
        char backup = str[0][i + size];
        str[0][i + size] = '\0';
        for (int j = 1; (flag) && (j < n); ++j) flag = contain(str[j], str[0] + i);
        if (flag) {
          if (strlen(str[0] + i) > strlen(ans)) {
            strcpy(ans, str[0] + i);
          } else if (strcmp(str[0] + i, ans) < 0) {
            strcpy(ans, str[0] + i);
          }
        }
        str[0][i + size] = backup;
      }
    }
    if (strlen(ans) < 3) {
      printf("no significant commonalities\n");
    } else {
      printf("%s\n", ans);
    }
  }
}
