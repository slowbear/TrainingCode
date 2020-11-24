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

constexpr int maxn = 1e6 + 7;

Pii a[maxn], new_a[maxn];

int origin[maxn], cnt[maxn], sa[maxn], second_sa[maxn], step[maxn];

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int n;
    scanf("%d", &n);
    int m = max(n, 10);
    rep(i, 0, n) scanf("%1d", &origin[i]);
    rep(i, 0, n) a[i].first = origin[i];
    rep(i, 0, n) a[i].second = i;
    rep(i, 0, n) step[i] = (1LL * i * i + 1) % n;
    rep(i, 0, m) cnt[i] = 0;
    rep(i, 0, n) { ++cnt[a[i].first]; }
    rep(i, 1, m) cnt[i] += cnt[i - 1];
    rev(i, 0, n) sa[--cnt[a[i].first]] = i;
    for (int gap = 1; gap <= n; gap <<= 1) {
      rep(i, 0, m) cnt[i] = 0;
      rep(i, 0, n) { ++cnt[a[step[a[i].second]].first]; }
      rep(i, 1, m) cnt[i] += cnt[i - 1];
      rev(i, 0, n) second_sa[--cnt[a[step[a[i].second]].first]] = i;
      rep(i, 0, m) cnt[i] = 0;
      rep(i, 0, n) { ++cnt[a[second_sa[i]].first]; }
      rep(i, 1, m) cnt[i] += cnt[i - 1];
      rev(i, 0, n) sa[--cnt[a[second_sa[i]].first]] = second_sa[i];
      int cur = 1;
      new_a[sa[0]].first = 0;
      new_a[sa[0]].second = a[step[a[sa[0]].second]].second;
      rep(i, 1, n) {
        new_a[sa[i]].first = ([](int x, int y) {
          return (a[x].first == a[y].first) &&
                 (a[step[a[x].second]].first == a[step[a[y].second]].first);
        })(sa[i], sa[i - 1])
                                 ? cur - 1
                                 : cur++;
        new_a[sa[i]].second = a[step[a[sa[i]].second]].second;
      }
      rep(i, 0, n) a[i] = new_a[i];
    }
    int cur = sa[n - 1];
    printf("Case #%d: ", ind);
    rep(i, 0, n) {
      printf("%d", origin[cur]);
      cur = step[cur];
    }
    printf("\n");
  }
}
