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

char alpha[16];

int digit[16];

char str[33];

void add(char &origin, int delta) {
  if (origin >= 'a' && origin <= 'z') {
    int val = origin + delta;
    if (val > 'z') val += 'A' - 'z';
    origin = val;
  } else {
    int val = origin + delta;
    if (val > 'Z') val += 'a' - 'Z';
    origin = val;
  }
}

int main() {
  scanf(" %s", str);
  int s = 0, t = 0;
  rep(i, 0, 32) {
    if (isdigit(str[i]))
      digit[t++] = str[i] - '0';
    else
      alpha[s++] = str[i];
  }
  rep(i, 0, 16) add(alpha[i], digit[i]);
  rep(i, 0, 4) rev(j, 0, 4) putchar(alpha[4 * i + j]);
  putchar('\n');
}
