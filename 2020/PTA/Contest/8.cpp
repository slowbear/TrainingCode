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

int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

char ch[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

char str[256];

int main() {
  int n;
  scanf("%d", &n);
  bool all_valid = true;
  rep(i, 0, n) {
    // fgets(str, sizeof(str), stdin);
    scanf(" %s", str);
    bool valid = true;
    rep(i, 0, 17) valid = valid && isdigit(str[i]);
    if (!valid) {
      all_valid = false;
      puts(str);
      continue;
    }
    int sum = 0;
    rep(i, 0, 17) sum += (str[i] - '0') * w[i];
    sum %= 11;
    if (ch[sum] != str[17]) {
      all_valid = false;
      puts(str);
    }
  }
  if (all_valid) puts("All passed");
}
