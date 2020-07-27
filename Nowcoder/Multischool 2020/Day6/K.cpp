#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (int)(V.size())

constexpr int maxn = 501000;

int a[maxn], n, k;

void solve1() {
  unordered_set<int> s, t;
  int i = 0, j = n - 1;
  while ((i < n) && (s.find(a[i]) == s.end())) {
    s.insert(a[i]);
    ++i;
  }
  while ((j >= 0) && (t.find(a[j]) == t.end())) {
    t.insert(a[j]);
    --j;
  }
  if (i <= j)
    printf("NO\n");
  else
    printf("YES\n");
}

int cnt[maxn];

bool f[maxn];

void solve2() {
  mem(cnt, 0);
  int tot = 0;
  rep(i, 0, k) {
    if (!cnt[a[i]]) ++tot;
    ++cnt[a[i]];
    f[i] = (tot == i + 1);
  }
  rep(i, k, n) {
    if (!cnt[a[i]]) ++tot;
    ++cnt[a[i]];
    if (cnt[a[i - k]] == 1) --tot;
    --cnt[a[i - k]];
    f[i] = f[i - k] && (tot == k);
  }
  unordered_set<int> s;
  for (int i = n - 1; i >= n - k; --i) {
    if (f[i]) {
      printf("YES\n");
      return;
    }
    if (s.find(a[i]) != s.end()) break;
    s.insert(a[i]);
  }
  printf("NO\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    rep(i, 0, n) scanf("%d", &a[i]);
    if (*max_element(a, a + n) > k) {
      printf("NO\n");
      continue;
    }
    if (k >= n) {
      solve1();
    } else {
      solve2();
    }
  }
}
