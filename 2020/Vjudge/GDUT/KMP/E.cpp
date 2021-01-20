#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int max_len = 2001000;

char str[max_len];

int f[max_len];

int main() {
  while (scanf(" %s", str) == 1) {
    if (str[0] == '.') break;
    int len = strlen(str);
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
      int cur = f[i];
      while (cur && (str[i] != str[cur])) cur = f[cur];
      f[i + 1] = str[i] == str[cur] ? cur + 1 : 0;
    }
    int cir = len - f[len];
    if (len % cir) {
      printf("1\n");
    } else {
      printf("%d\n", len / cir);
    }
  }
}
