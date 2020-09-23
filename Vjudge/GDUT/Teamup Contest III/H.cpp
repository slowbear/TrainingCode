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

int a[maxn], b[maxn], str[maxn];

int f[maxn];

void pre_kmp(int str[], int len) {
  f[0] = 0;
  f[1] = 0;
  rep(i, 1, len) {
    int j = f[i];
    while (j && (str[i] != str[j]))
      j = f[j];
    f[i + 1] = (str[i] == str[j] ? j + 1 : 0);
  }
}

int kmp(int str[], int sub[], int len, int target) {
  int j = 0, ans = 0;
  rep(i, 0, len) {
    while (j && (str[i] != sub[j]))
      j = f[j];
    if (str[i] == sub[j])
      ++j;
    if (j == target)
      ++ans;
  }
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  rep(ind, 1, T + 1) {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    rep(i, 0, n) scanf("%d", &a[i]);
    rep(i, 0, m) scanf("%d", &b[i]);
    b[m] = -1;
    pre_kmp(b, m);
    int cnt = 0;
    rep(i, 0, p) {
      int cur = i, last = 0;
      while (cur < n) {
        str[last++] = a[cur];
        cur += p;
      }
      str[last] = -1;
      cnt += kmp(str, b, last, m);
    }
    printf("Case #%d: %d\n", ind, cnt);
  }
}
