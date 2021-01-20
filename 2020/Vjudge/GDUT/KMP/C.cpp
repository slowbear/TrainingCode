#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int max_len = 101000;

char str[max_len];

int f[max_len];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %s", str);
    int len = strlen(str);
    f[0] = f[1] = 0;
    for (int i = 1; i < len; ++i) {
      int cur = f[i];
      while (cur && (str[i] != str[cur])) cur = f[cur];
      f[i + 1] = str[i] == str[cur] ? cur + 1 : 0;
    }
    int cir = len - f[len];
    if (f[len] && (len % cir == 0)) {
      printf("0\n");
    } else {
      printf("%d\n", cir - len % cir);
    }
  }
}
