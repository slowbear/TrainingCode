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

constexpr int maxn = 501000;

int p[maxn];

int nxt[maxn];

int st[maxn], last;

int rev(int x) {
  last = 0;
  while (x) st[last++] = x, x = nxt[x];
  for (int i = last - 1; i > 0; --i) nxt[st[i]] = st[i - 1];
  nxt[st[0]] = 0;
  return st[last - 1];
}

void add(int cur, int ext) {
  while (nxt[cur]) cur = nxt[cur];
  nxt[cur] = ext;
}

void solve(int *l, int *r, int cur) {
  // if (!cur) return;
  while (cur--) {
    int len = r - l, half_len = len >> 1, *p = l;
    rep(i, 0, half_len) p[i] = rev(p[i]);
    rep(i, half_len, len) add(p[i], p[len - i - 1]);
    // solve(l + half_len, r, cur - 1);
    l += half_len;
  }
}

bool is_first;

void print(int x) {
  last = 0;
  while (x) {
    st[last++] = x;
    x = nxt[x];
  }
  for (int i = last - 1; i >= 0; --i) {
    if (is_first) {
      printf("%d", st[i]);
      is_first = false;
    } else {
      printf(" %d", st[i]);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    int n, k;
    scanf("%d%d", &n, &k);
    int len = n * (1 << (k + 1));
    rep(i, 0, len) {
      scanf("%d", &p[i]);
      nxt[p[i]] = 0;
    }
    solve(p, p + len, k);
    is_first = true;
    rep(i, len - (n << 1), len) print(p[i]);
    printf("\n");
  }
}
