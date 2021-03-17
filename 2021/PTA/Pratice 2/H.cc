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

unordered_map<string, int> f;

int main() {
  int n;
  cin >> n;
  string name, winner;
  double sum = 0;
  rep(i, 0, n) {
    int score;
    cin >> name >> score;
    f[name] = score;
    sum += score;
  }
  double cur = sum;
  sum /= 2.0 * n;
  for (auto &p : f) {
    if (abs(sum - p.second) < cur) {
      cur = abs(sum - p.second);
      winner = p.first;
    }
  }
  cout << round(sum) << ' ' << winner << endl;
}
