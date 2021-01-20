#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) static_cast<int>(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 1e6 + 7;

int a[maxn], b[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    int div = *min_element(a, a + n);
    sort(a, a + n);
    bool check = true;
    rep(i, 0, n) {
      check = check && ((a[i] == b[i]) || !(a[i] % div));
      if (!check) break;
    }
    if (check)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
