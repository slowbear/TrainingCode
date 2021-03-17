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

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k1, k2, w, b;
    scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
    k1 += k2;
    int k3 = 2 * n - k1;
    if (k1 & 1) k1 ^= 1;
    if (k3 & 1) k3 ^= 1;
    puts(k1 >= 2 * w && k3 >= 2 * b ? "YES" : "NO");
  }
}
