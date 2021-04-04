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

string str;

int main() {
  int n;
  char fill_ch;
  cin >> n >> fill_ch;
  scanf("\n");
  getline(cin, str);
  int len = str.length();
  if (n > len) {
    rep(i, 0, n - len) cout << fill_ch;
    cout << str << endl;
  } else {
    rep(i, len - n, len) cout << str[i];
    cout << endl;
  }
}
