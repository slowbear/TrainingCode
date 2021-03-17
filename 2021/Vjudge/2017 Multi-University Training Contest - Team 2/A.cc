// #include <bits/extc++.h>
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

constexpr int maxn = 1e5 + 7;

char a[maxn], b[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x, y, diff = 0;
    scanf("%d%d%d", &n, &x, &y);
    scanf(" %s %s", a, b);
    rep(i, 0, n) if (a[i] != b[i])++ diff;
    int common = n - diff;
    puts([&]() {
      if (diff < abs(x - y)) return false;
      diff -= abs(x - y);
      if (diff / 2 + common < min(x, y)) return false;
      return true;
    }()
             ? "Not lying"
             : "Lying");
  }
}
