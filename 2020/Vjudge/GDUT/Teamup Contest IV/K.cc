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

constexpr int maxn = 10100;

constexpr int gap = 700;

bool ch[gap];

int prime[maxn], last;

bool is_prime[maxn];

void init() {
  mem(is_prime, 1);
  is_prime[1] = false;
  rep(i, 2, maxn) {
    if (is_prime[i]) prime[last++] = i;
    rep(j, 0, last) {
      if (i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (!(i % prime[j])) break;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  init();
  rep(i, 1, T + 1) {
    int n, s;
    scanf("%d%d", &n, &s);
    int common = max(n - s, 0);
    n -= common;
    s += common;
    printf("Case #%d: ", i);
    if (!n) {
      puts("Yes");
      continue;
    }
    if (min(s, n) >= gap) {
      puts("No");
      continue;
    }
    rep(i, 1, n + 1) {
      rep(j, 1, n + 1) {
        if ((j + s) % i == 0) add(i, n + j);
      }
    }
  }
}
