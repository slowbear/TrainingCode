#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pii = pair<int, int>;
using VI = vector<int>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define rev(i, a, b) for (auto i = (b - 1); i >= (a); --i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define gcur(i, u) for (auto i = cur[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 301000;

int h[maxn], f[maxn];

stack<int> s1, s2;

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d", &h[i]);
  f[0] = 0;
  s1.push(0);
  s2.push(0);
  rep(i, 1, n) {
    f[i] = f[i - 1] + 1;
    while (!s1.empty() && (h[i] > h[s1.top()])) {
      f[i] = min(f[s1.top()] + 1, f[i]);
      s1.pop();
    }
    if (!s1.empty()) f[i] = min(f[s1.top()] + 1, f[i]);
    while (!s1.empty() && (h[i] == h[s1.top()])) s1.pop();
    s1.push(i);
    while (!s2.empty() && (h[i] < h[s2.top()])) {
      f[i] = min(f[s2.top()] + 1, f[i]);
      s2.pop();
    }
    if (!s2.empty()) f[i] = min(f[s2.top()] + 1, f[i]);
    while (!s2.empty() && (h[i] == h[s2.top()])) s2.pop();
    s2.push(i);
  }
  printf("%d\n", f[n - 1]);
}
