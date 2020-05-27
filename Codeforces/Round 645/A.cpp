#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", (n * m + 1) / 2);
  }
}
