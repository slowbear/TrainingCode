#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 3e5 + 7;

int l[maxn], r[maxn];

int n, m;

int cnt[maxn];

bool check(int gap) {
  fill(cnt + 1, cnt + n + 1, 0);
  rep(i, 0, m) {
    if (r[i] - l[i] + 1 >= gap) {
      ++cnt[l[i] + gap - 1];
      --cnt[r[i] + 1];
    }
  }
  rep(i, 2, n) cnt[i] += cnt[i - 1];
  return *max_element(cnt + 1, cnt + n + 1) >= gap;
}

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 0, m) scanf("%d%d", &l[i], &r[i]);
  int l = 0, r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
}
