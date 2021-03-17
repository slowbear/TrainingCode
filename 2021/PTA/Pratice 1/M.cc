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

constexpr int maxn = 1010;

int lc[maxn], rc[maxn], fa[maxn], val[maxn], total;

int insert(int rt, int key) {
  if (!rt) {
    lc[total] = rc[total] = fa[total] = 0;
    val[total] = key;
    return total++;
  }
  if (key > val[rt]) {
    lc[rt] = insert(lc[rt], key);
    fa[lc[rt]] = rt;
  } else {
    rc[rt] = insert(rc[rt], key);
    fa[rc[rt]] = rt;
  }
  return rt;
}

int tag[maxn], cnt;

int main() {
  int n, rt = 0;
  total = 1;
  scanf("%d", &n);
  rep(i, 0, n) {
    int x;
    scanf("%d", &x);
    rt = insert(rt, x);
  }
  bool flag = true, first_print = true;
  queue<int> que;
  que.push(rt);
  cnt = 1;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    tag[u] = cnt++;
    if (tag[fa[u]] != tag[u] / 2) flag = false;
    if (!lc[u] && rc[u]) flag = false;
    if (!first_print) putchar(' ');
    printf("%d", val[u]);
    first_print = false;
    if (lc[u]) que.push(lc[u]);
    if (rc[u]) que.push(rc[u]);
  }
  printf("\n");
  puts(flag ? "YES" : "NO");
}
