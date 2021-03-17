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

constexpr int maxn = 1e5 + 7;

char str[maxn];

bool f[maxn][2][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %s", str);
    int len = strlen(str), cur = str[len - 1] - '0';
    f[len - 1][cur][0] = true;
    f[len - 1][cur ^ 1][0] = false;
    f[len - 1][0][1] = f[len - 1][1][1] = true;
    rev(i, 0, len - 1) {
      cur = str[i] - '0';
      f[i][cur][0] = cur ? f[i + 1][1][0] || f[i + 1][1][1]
                         : f[i + 1][1][0] || f[i + 1][1][1] || f[i + 1][0][0] || f[i + 1][0][1];
      f[i][cur ^ 1][0] = false;
      f[i][0][1] = f[i + 1][0][0];
      f[i][1][1] = f[i + 1][1][0];
    }
    puts(f[0][0][0] || f[0][0][1] || f[0][1][0] || f[0][1][1] ? "YES" : "NO");
  }
}
