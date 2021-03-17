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

int sex[50];

string name[50];

bool use[50];

int main() {
  int n;
  cin >> n;
  mem(use, false);
  rep(i, 0, n) cin >> sex[i] >> name[i];
  rep(i, 0, n) if (!use[i]) {
    rev(j, i + 1, n) if (!use[j] && sex[i] != sex[j]) {
      cout << name[i] << " " << name[j] << endl;
      use[i] = use[j] = true;
      break;
    }
  }
}
