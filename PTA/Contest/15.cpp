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

int ch[maxn][2], val[maxn], fa[maxn], total;

void init() {
  ch[0][0] = ch[0][1] = fa[0] = 0;
  total = 1;
}

int new_node(int key) {
  int u = total++;
  ch[u][0] = ch[u][1] = fa[0] = 0;
  val[u] = key;
  return u;
}

int insert(int rt, int key) {
  if (rt) {
    if (key < val[rt]) {
      ch[rt][1] = insert(ch[rt][1], key);
      fa[ch[rt][1]] = rt;
    } else {
      ch[rt][0] = insert(ch[rt][0], key);
      fa[ch[rt][0]] = rt;
    }
    return rt;
  } else {
    int u = new_node(key);
    return fa[u] = u;
  }
}

int step[maxn];

void bfs(int rt) {
  queue<int> que;
  que.push(rt);
  VI ans;
  bool is_valid = true;
  int cur = 1;
  while (!que.empty()) {
    int u = que.front();
    step[u] = cur++;
    if ((fa[u] != u) && (step[fa[u]] != step[u] / 2)) is_valid = false;
    if (!ch[u][0] && ch[u][1]) is_valid = false;
    que.pop();
    ans.pb(val[u]);
    if (ch[u][0]) que.push(ch[u][0]);
    if (ch[u][1]) que.push(ch[u][1]);
  }
  printf("%d", ans[0]);
  rep(i, 1, SZ(ans)) printf(" %d", ans[i]);
  puts(is_valid ? "\nYES" : "\nNO");
}

int main() {
  int n, rt = 0;
  scanf("%d", &n);
  init();
  rep(i, 0, n) {
    int x;
    scanf("%d", &x);
    rt = insert(rt, x);
  }
  bfs(rt);
}
