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

int count_one(int x) {
  int ret = 0;
  while (x) ++ret, x &= x - 1;
  return ret;
}

int high_bit(int x) {
  rev(i, 0, 30) if (x & (1 << i)) return 1 << i;
  return 0;
}

int remove_bit(int u, int count) {
  rev(i, 0, 30) if (u & (1 << i)) {
    if (count) {
      u ^= 1 << i;
      --count;
    }
  }
  return u;
}

bool check(int u, int v) {
  if (u > v) return false;
  if (u == v) return true;
  int extra = count_one(u) - count_one(v);
  if (extra < 0) return false;
  int bit = high_bit(v);
  return (u & bit) ? check(u ^ bit, v ^ bit) : check(remove_bit(u, extra + 1), v ^ bit);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int u, v;
    scanf("%d%d", &u, &v);
    puts(check(u, v) ? "YES" : "NO");
  }
}
