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

// char a[1000], b[1000];

bool is_num(const char *str) {
  int len = strlen(str);
  if (len > 4) return false;
  rep(i, 0, len) if (!isdigit(str[i])) return false;
  return true;
}

char str[1000];

int main() {
  // scanf("%s %s", a, b);
  cin.getline(str, 1000);
  int pos = find(str, str + 1000, ' ') - str;
  str[pos] = '\0';
  char *a = str;
  char *b = str + pos + 1;
  int x = 0, y = 0;
  if (is_num(a)) x = stoi(a);
  if (x < 1 || x > 1000) x = 0;
  if (is_num(b)) y = stoi(b);
  if (y < 1 || y > 1000) y = 0;
  printf("%s + %s = ", (x ? a : "?"), (y ? b : "?"));
  if (x && y)
    printf("%d", x + y);
  else
    printf("?");
}
