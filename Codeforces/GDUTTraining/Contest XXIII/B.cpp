#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char str[100];

int convert(const char *str) {
  int len = strlen(str), num = 0;
  for (int i = 0; i < len; ++i) num = num * 10 + (str[i] - '0');
  return num;
}

int main() {
  int n;
  scanf("%d", &n);
  bool flag = true;
  for (int i = 1; flag && (i <= n); ++i) {
    scanf(" %s", str);
    if ((str[0] != 'm') && (convert(str) != i)) flag = false;
  }
  if (flag)
    printf("makes sense\n");
  else
    printf("something is fishy\n");
}
