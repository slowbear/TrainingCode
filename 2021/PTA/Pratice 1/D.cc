#include <bits/extc++.h>
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

constexpr int maxn = 101000;

bool is_prime[maxn];

int prime[maxn], last;

int main() {
  mem(is_prime, true);
  is_prime[1] = false;
  last = 0;
  rep(i, 2, maxn) {
    if (is_prime[i]) prime[last++] = i;
    rep(j, 0, last) {
      if (1LL * i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (!(i % prime[j])) break;
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    bool flag = n < maxn ? is_prime[n] : true;
    if (n >= maxn) rep(i, 0, last) if (!(n % prime[i])) flag = false;
    puts(flag ? "Yes" : "No");
  }
}
