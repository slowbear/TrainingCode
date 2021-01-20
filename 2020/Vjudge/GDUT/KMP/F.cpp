#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int max_len = 401000;

char str[max_len];

int f[max_len];

int ans[max_len], last;

int main() {
  while (scanf(" %s", str) == 1) {
    int len = strlen(str);
    f[0] = 0;
    f[1] = 0;
    for (int i = 1; i < len; ++i) {
      int cur = f[i];
      while (cur && (str[i] != str[cur])) cur = f[cur];
      f[i + 1] = str[i] == str[cur] ? cur + 1 : 0;
    }
    last = 0;
    int cur = len;
    while (cur) {
      ans[last++] = cur;
      cur = f[cur];
    }
    for (int i = last - 1; i > 0; --i) printf("%d ", ans[i]);
    printf("%d\n", ans[0]);
  }
}
