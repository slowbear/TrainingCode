#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define gre(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define pb push_back
#define mp make_pair
#define SZ(V) (int)(V.size())

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    double cur;
    scanf("%lf", &cur);
    if (cur > 1.0)
      printf("No\n");
    else
      printf("Yes\n");
  }
}
