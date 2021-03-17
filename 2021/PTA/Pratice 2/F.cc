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

constexpr int maxlen = 300;

string g[maxlen], null_line;

int main() {
  char ch;
  int n;
  cin >> ch >> n;
  getline(cin, null_line);
  rep(i, 0, n) getline(cin, g[i]);
  bool flag = true;
  rep(i, 0, n) rep(j, 0, n) if (g[i][j] != g[n - 1 - i][n - 1 - j]) flag = false;
  if (flag) puts("bu yong dao le");
  rep(i, 0, n) {
    rep(j, 0, n) putchar(g[n - 1 - i][n - 1 - j] == '@' ? ch : g[n - 1 - i][n - 1 - j]);
    putchar('\n');
  }
}
