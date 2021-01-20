#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 101000;

char str[maxn];

int ex[maxn];

int main() {
  while (scanf(" %s", str) == 1) {
    int first = strlen(str);
    scanf(" %s", str + first);
    int len = strlen(str), cur = 0;
    ex[0] = 0;
    for (int i = 1; i < len; ++i) {
      ex[i] = 0;
      if (cur + ex[cur] > i) {
        ex[i] = min(ex[i - cur], ex[cur] + cur - i);
      }
      while (str[i + ex[i]] == str[ex[i]]) ++ex[i];
      if (i + ex[i] > cur + ex[cur]) cur = i;
    }
    bool done = false;
    for (int i = first; i < len; ++i) {
      if (i + ex[i] >= len) {
        int len = min(ex[i], first);
        for (int j = 0; j < len; ++j) printf("%c", str[i + j]);
        printf(" %d\n", len);
        done = true;
        break;
      }
    }
    if (!done) printf("0\n");
  }
}
