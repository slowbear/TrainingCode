#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int max_len = 1010;

char s[max_len], t[max_len];

int f[max_len];

int main() {
  while (true) {
    scanf(" %s", s);
    if (s[0] == '#') break;
    scanf(" %s", t);
    f[0] = f[1] = 0;
    int len_s = strlen(s), len_t = strlen(t);
    for (int i = 1; i < len_t; ++i) {
      int cur = f[i];
      while (cur && (t[cur] != t[i])) cur = f[cur];
      f[i + 1] = t[cur] == t[i] ? cur + 1 : 0;
    }
    int cur = 0, ans = 0;
    for (int i = 0; i < len_s; ++i) {
      while (cur && (s[i] != t[cur])) cur = f[cur];
      if (s[i] == t[cur]) ++cur;
      if (cur == len_t) {
        ++ans;
        cur = 0;
      }
    }
    printf("%d\n", ans);
  }
}
