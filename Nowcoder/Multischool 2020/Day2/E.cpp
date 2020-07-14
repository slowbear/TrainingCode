#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define VI vector<int>
#define SZ(V) (V.size())

constexpr int max_v = 1 << 18;

int n, cnt[max_v], cur[max_v], ans[max_v];

void FWT(int *src) {
  for (int sz = 2; sz <= max_v; sz <<= 1) {
    int step = sz >> 1;
    for (int i = 0; i < max_v; i += sz) {
      for (int j = i; j < i + step; ++j) {
        int a = src[j], b = src[j + step];
        src[j] = a + b;
        src[j + step] = a - b;
      }
    }
  }
}

void IFWT(int *src) {
  for (int sz = 2; sz <= max_v; sz <<= 1) {
    int step = sz >> 1;
    for (int i = 0; i < max_v; i += sz) {
      for (int j = i; j < i + step; ++j) {
        int a = src[j], b = src[j + step];
        src[j] = (a + b) >> 1;
        src[j + step] = (a - b) >> 1;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  mem(cnt, 0);
  mem(ans, 0);
  rep(i, 0, n) {
    int x;
    scanf("%d", &x);
    cnt[x] = 1;
    if (x > ans[1]) ans[1] = x;
  }
  cpy(cur, cnt);
  FWT(cnt);
  rep(i, 2, 20) {
    FWT(cur);
    rep(j, 0, max_v) cur[j] *= cnt[j];
    IFWT(cur);
    rep(j, 0, max_v) if (cur[j]) cur[j] = 1;
    per(j, max_v - 1, 0) if (cur[j]) {
      ans[i] = j;
      break;
    }
  }
  rep(i, 1, n + 1) {
    if (i >= 20) ans[i] = ans[i - 2];
    printf("%d ", ans[i]);
  }
  printf("\n");
}
