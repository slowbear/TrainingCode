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

int a[110];

int ans[110], last;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 1, n + 1) scanf("%d", &a[i]);
    a[0] = -1;
    last = 0;
    sort(a + 1, a + n + 1);
    rep(i, 1, n + 1) if (a[i] != a[i - 1]) ans[last++] = a[i];
    rep(i, 1, n + 1) if (a[i] == a[i - 1]) ans[last++] = a[i];
    rep(i, 0, last) printf("%d%c", ans[i], " \n"[i == last - 1]);
  }
}
