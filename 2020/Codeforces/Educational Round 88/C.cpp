#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int h, c, t;

double calc(int k) {
  double aver = (h + c) / 2.0;
  return abs((aver * 2 * k + h) / (2 * k + 1.0) - t);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &h, &c, &t);
    double aver = (h + c) / 2.0;
    if (aver >= t) {
      printf("2\n");
    } else {
      int k = trunc((h - t) / (t - aver) / 2.0);
      if (calc(k + 1) < calc(k)) ++k;
      printf("%d\n", 2 * k + 1);
    }
  }
}
