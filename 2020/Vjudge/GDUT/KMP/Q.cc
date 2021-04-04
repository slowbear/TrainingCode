#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 301000;

char str[maxn], word[maxn];

int ex[maxn];

int main() {
  while (scanf(" %s", word) == 1) {
    int len = strlen(word);
    str[0] = '#';
    for (int i = 0; i < len; ++i) {
      str[2 * i + 1] = word[i];
      str[2 * (i + 1)] = '#';
    }
    str[2 * len + 1] = '\0';
    len = len * 2 + 1;
    int cur = 0;
    ex[0] = 0;
    for (int i = 1; i < len; ++i) {
      ex[i] = 0;
      if (cur + ex[cur] > i) ex[i] = min(cur + ex[cur] - i, ex[2 * cur - i]);
      while ((i + ex[i] + 1 < len) && (i - ex[i] - 1 >= 0) &&
             (str[i + ex[i] + 1] == str[i - ex[i] - 1]))
        ++ex[i];
      if (i + ex[i] > cur + ex[cur]) cur = i;
    }
    int ans = 1;
    for (int i = 1; i < len; ++i)
      if (ex[i] > ans) ans = ex[i];
    printf("%d\n", ans);
  }
}
