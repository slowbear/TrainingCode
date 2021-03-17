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
const int maxn = 1e6 + 7;
int ht[maxn];
void init(int n) {
  ht[1] = 1;
  for (int i = 2; i <= n; i++) {
    ht[i] = ht[i - 1];
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) ht[i] = ht[i] - (i - 1) / j + i / j;
    }
    cout << ht[i] << " ";
  }
  cout << endl;
  for (int i = 2; i <= n; i++) {
    int res = 0;
    for (int j = 1; j <= i; j++) {
      res += i / j;
    }
    cout << res << " ";
  }
  cout << endl;
}
int main() { init(10); }
