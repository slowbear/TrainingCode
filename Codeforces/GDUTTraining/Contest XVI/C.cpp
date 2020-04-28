#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int n, time, maximum = 0;
  scanf("%d%d", &n, &time);
  for (int i = 0; i < n; ++i) {
    int h;
    scanf("%d", &h);
    if (time <= 0) {
      printf("1\n");
      continue;
    }
    if (h > maximum) maximum = h;
    printf("%d\n", time / maximum + 1 + (time % maximum >= h));
    time -= h;
  }
}
