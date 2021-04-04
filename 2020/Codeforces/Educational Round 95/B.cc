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

constexpr int maxn = 110;

int a[maxn], l[maxn], gap[maxn], lock_prefix[maxn];

VI unlock_numbers;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &a[i]);
    rep(i, 0, n) scanf("%d", &l[i]);
    unlock_numbers.clear();
    rep(i, 0, n) if (!l[i]) unlock_numbers.pb(a[i]);
    sort(unlock_numbers.begin(), unlock_numbers.end(), greater<int>());
    int ind = 0;
    rep(i, 0, n) if (!l[i]) a[i] = unlock_numbers[ind++];
    rep(i, 0, n) printf("%d ", a[i]);
    printf("\n");
  }
}
