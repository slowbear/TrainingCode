#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 201000;

__int128 a[maxn], b[maxn];

int st[maxn], last;

inline void read(__int128 &X) {
  X = 0;
  int w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  if (w) X = -X;
}

void print(__int128 x) {
  if (!x) return;
  if (x < 0) putchar('-'), x = -x;
  print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) read(a[i]);
    rep(i, 0, n) read(b[i]);
    rep(i, 1, n) a[i] += a[i - 1];
    rep(i, 1, n) b[i] = min(b[i], b[i - 1]);
    last = 0;
    st[last++] = 0;
    rep(i, 1, n) if (a[i] > a[st[last - 1]]) st[last++] = i;
    __int128 l = 0, r = b[0], ans = 0;
    while (l < r) {
      int u = st[--last];
      ans += a[u] * (b[u] - l);
      l = b[u];
    }
    printf("Case #%d: ", index);
    print(r);
    printf(" ");
    print(ans);
    printf("\n");
  }
}
