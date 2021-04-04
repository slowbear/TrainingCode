#include <bits/stdc++.h>

using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define per(i, b, a) for (auto i = (b); i != (a); --i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define VI vector<int>
#define SZ(V) (V.size())

constexpr int maxn = 401000;

char s1[maxn], s2[maxn];

int main() {
  while (scanf(" %s %s", s1, s2) == 2) {
    int l1 = strlen(s1), l2 = strlen(s2), sum = l1 + l2;
    rep(i, l1, sum) s1[i] = s2[i - l1];
    rep(i, l2, sum) s2[i] = s1[i - l2];
    int flag = strncmp(s1, s2, sum);
    if (flag < 0) fputs("<\n", stdout);
    if (flag == 0) fputs("=\n", stdout);
    if (flag > 0) fputs(">\n", stdout);
  }
}
