#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int maxn = 501000;

struct Query {
  int l, r, index;
};

inline long long gcd(long long x, long long y) {
  while (y) {
    long long p = x % y;
    x = y;
    y = p;
  }
  return x;
}

int sep;

long long cx, cy;

bool operator<(const Query &x, const Query &y) {
  if (x.l / sep != y.l / sep) return x.l < y.l;
  if ((x.l / sep) & 1) return x.r < y.r;
  return x.r > y.r;
}

int color[maxn];

long long cnt[maxn];

Query query[maxn];

pair<long long, long long> ans[maxn];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  sep = sqrt(n);
  for (int i = 1; i <= n; ++i) scanf("%d", &color[i]);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &query[i].l, &query[i].r);
    query[i].index = i;
  }
  sort(query, query + m);
  cnt[color[1]] = 1;
  int l = 1, r = 1;
  cx = cy = 0;
  for (int i = 0; i < m; ++i) {
    while (l > query[i].l) {
      --l;
      cx += cnt[color[l]];
      cy += r - l;
      ++cnt[color[l]];
    }
    while (r < query[i].r) {
      ++r;
      cx += cnt[color[r]];
      cy += r - l;
      ++cnt[color[r]];
    }
    while (l < query[i].l) {
      cx -= cnt[color[l]] - 1;
      cy -= r - l;
      --cnt[color[l]];
      ++l;
    }
    while (r > query[i].r) {
      cx -= cnt[color[r]] - 1;
      cy -= r - l;
      --cnt[color[r]];
      --r;
    }
    if (cx) {
      long long d = gcd(cx, cy);
      ans[query[i].index] = make_pair(cx / d, cy / d);
    } else {
      ans[query[i].index] = make_pair(0LL, 1LL);
    }
  }
  for (int i = 0; i < m; ++i) printf("%lld/%lld\n", ans[i].first, ans[i].second);
}
