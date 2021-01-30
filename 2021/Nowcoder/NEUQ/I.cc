#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
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

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    bool flag = false;
    scanf("%d", &n);
    rep(k, 2, 15) {
      int cur = (1LL << k) - 1;
      if (!(n % cur)) flag = true;
    }
    puts(flag ? "YE5" : "N0");
  }
}
