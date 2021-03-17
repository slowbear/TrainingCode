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

priority_queue<string, vector<string>, greater<string>> user[101];

int cnt[101];

int main() {
  int n, g, k;
  cin >> n >> g >> k;
  string email;
  int sum = 0;
  rep(i, 0, n) {
    int score;
    cin >> email >> score;
    user[score].push(email);
    ++cnt[score];
    if (score >= 60 && score < g) sum += 20;
    if (score >= g) sum += 50;
  }
  printf("%d\n", sum);
  int cur = 100, rk = 1;
  while (rk <= k) {
    while (user[cur].empty()) --cur;
    cout << rk << ' ' << user[cur].top() << ' ' << cur << endl;
    user[cur].pop();
    if (user[cur].empty()) rk += cnt[cur];
  }
}
