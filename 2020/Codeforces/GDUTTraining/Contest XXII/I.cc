#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int s;
  scanf("%d", &s);
  int x = s % 3;
  if (x == 0) {
    for (int i = 0; i < s / 3; ++i) printf("21");
    printf("\n");
  }
  if (x == 1) {
    for (int i = 0; i < s / 3; ++i) printf("12");
    printf("1\n");
  }
  if (x == 2) {
    for (int i = 0; i < s / 3; ++i) printf("21");
    printf("2\n");
  }
}
