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

constexpr int base = 26;

int main() {
  LL L, n;
  scanf("%lld%lld", &L, &n);
  LL rank = 1;
  rep(i, 0, L) rank *= base;
  rank -= n;
  stack<char> ans;
  rep(i, 0, L) {
    ans.push(rank % base + 'a');
    rank /= base;
  }
  rep(i, 0, L) {
    putchar(ans.top());
    ans.pop();
  }
  putchar('\n');
}
