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

// char str[maxn], exstr[maxn];

string str, exstr;

int f[maxn];

// int calc(char str[], int len) {
int calc(const string &str) {
  int cur = 0, ans = 0;
  rep(i, 1, str.length()) {
    if (cur + f[cur] > i) f[i] = f[2 * cur - i];
    while ((i + f[i] + 1 < str.length()) && (i - f[i] - 1 >= 0) &&
           (str[i + f[i] + 1] == str[i - f[i] - 1]))
      ++f[i];
    if (f[i] > ans) ans = f[i];
  }
  return ans;
}

int main() {
  // fgets(str, maxn, stdin);
  getline(cin, str);
  // int len = strlen(str), cur = 1;
  // rep(i, 0, len) {
  rep(i, 0, str.length()) {
    // exstr[cur++] = -1;
    // exstr[cur++] = str[i];
    exstr += -2;
    exstr += str[i];
  }
  // exstr[cur++] = -1;
  exstr += -2;
  // printf("%d\n", calc(exstr, cur));
  cout << calc(exstr) << endl;
}
