#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int p = 10007;

const int maxn = 201000;

char str[maxn];

int ex[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int len, cur = 0;
    scanf("%d", &len);
    scanf(" %s", str);
    int ans = len % p;
    ex[0] = 0;
    for (int i = 1; i < len; ++i) {
      ex[i] = 0;
      if (cur + ex[cur] > i) ex[i] = min(ex[i - cur], cur + ex[cur] - i);
      while (str[i + ex[i]] == str[ex[i]]) ++ex[i];
      if (i + ex[i] > cur + ex[cur]) cur = i;
      ans = (ans + ex[i]) % p;
    }
    printf("%d\n", ans);
  }
}
