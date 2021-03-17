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

constexpr int maxn = 1000;

constexpr double eps = 1e-7;

int sex[maxn];

inline void print_with_sex(int x) {
  if (sex[x]) putchar('-');
  printf("%d", x);
}

Pii read() {
  int id, sex = 0;
  char ch;
  while (true) {
    ch = getchar();
    if (ch == '-' || isdigit(ch)) break;
  }
  if (ch == '-') sex = 1, ch = getchar();
  id = ch - '0';
  while (isdigit(ch = getchar())) id = id * 10 + ch - '0';
  return {id, sex};
}

int score[maxn], n, m;

bitset<maxn> g[maxn];

double f[maxn], ff;

double query(int u, int v) {
  double ret = 0;
  rep(i, 0, m) if (g[i][u] && g[i][v]) ret += 1.0 / score[i];
  return ret;
}

VI fa, fb;

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 0, m) {
    scanf("%d", &score[i]);
    rep(j, 0, score[i]) {
      auto p = read();
      sex[p.first] = p.second;
      g[i].set(p.first);
    }
  }
  int x = read().first, y = read().first;
  bool flag = true;
  rep(i, 0, n) f[i] = sex[x] != sex[i] ? query(x, i) : 0;
  ff = *max_element(f, f + n);
  rep(i, 0, n) if (abs(f[i] - ff) <= eps) fa.pb(i);
  if (abs(f[y] - ff) > eps) flag = false;
  //====================================================
  rep(i, 0, n) f[i] = sex[y] != sex[i] ? query(y, i) : 0;
  ff = *max_element(f, f + n);
  rep(i, 0, n) if (abs(f[i] - ff) <= eps) fb.pb(i);
  if (abs(f[x] - ff) > eps) flag = false;
  if (flag) {
    print_with_sex(x);
    putchar(' ');
    print_with_sex(y);
    putchar('\n');
  } else {
    for (int u : fa) {
      print_with_sex(x);
      putchar(' ');
      print_with_sex(u);
      putchar('\n');
    }
    for (int u : fb) {
      print_with_sex(y);
      putchar(' ');
      print_with_sex(u);
      putchar('\n');
    }
  }
}
