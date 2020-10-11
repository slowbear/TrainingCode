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

constexpr int maxn = 101000;

char str[maxn], sub[maxn];

bool ch[256];

int main() {
  fgets(str, sizeof(str), stdin);
  fgets(sub, sizeof(sub), stdin);
  int len = strlen(sub);
  rep(i, 0, len) ch[sub[i]] = true;
  len = strlen(str);
  rep(i, 0, len) if (!ch[str[i]]) putchar(str[i]);
  puts("");
}
