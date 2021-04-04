#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 201000;

int a[maxn], b[maxn];

VI vec;

unordered_map<int, int> f;

int fa[maxn];

bool is_tree[maxn], vis[maxn];

int find_fa(int x) { return x == fa[x] ? x : fa[x] = find_fa(fa[x]); }

void join(int u, int v, bool flag) {
  fa[v] = u;
  is_tree[u] = flag;
}

int main() {
  int T;
  scanf("%d", &T);
  rep(index, 1, T + 1) {
    int n;
    scanf("%d", &n);
    vec.clear();
    rep(i, 0, n) {
      scanf("%d%d", &a[i], &b[i]);
      vec.pb(a[i]);
      vec.pb(b[i]);
    }
    sort(vec.begin(), vec.end());
    int total = unique(vec.begin(), vec.end()) - vec.begin();
    rep(i, 0, total) {
      f[vec[i]] = i;
      fa[i] = i;
      is_tree[i] = true;
      vis[i] = false;
    }
    rep(i, 0, n) {
      a[i] = f[a[i]];
      b[i] = f[b[i]];
    }
    rep(i, 0, n) {
      a[i] = find_fa(a[i]);
      b[i] = find_fa(b[i]);
      bool check = (a[i] != b[i]) && is_tree[a[i]] && is_tree[b[i]];
      join(a[i], b[i], check);
    }
    int ans = total;
    rep(i, 0, total) {
      int u = find_fa(i);
      if (vis[u]) continue;
      vis[u] = true;
      if (is_tree[u]) --ans;
    }
    printf("Case #%d: %d\n", index, ans);
  }
}
