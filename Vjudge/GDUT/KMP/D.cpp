#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int max_len = 1001000;

char str[max_len];

int f[max_len];

int main() {
  int len = 0, ind = 0;
  while (scanf("%d", &len) == 1) {
    if (!len) break;
    ++ind;
    scanf(" %s", str);
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
      int cur = f[i];
      while (cur && (str[i] != str[cur])) cur = f[cur];
      f[i + 1] = str[i] == str[cur] ? cur + 1 : 0;
    }
    printf("Test case #%d\n", ind);
    for (int i = 2; i <= len; ++i) {
      int cir = i - f[i];
      if (f[i] && (i % cir == 0)) printf("%d %d\n", i, i / cir);
    }
    printf("\n");
  }
}
