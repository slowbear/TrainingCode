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

struct Message {
  int score, id, sex;
};

map<string, Message> students;

set<string> keep[105];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  string name;
  rep(i, 0, n) {
    int score, sex, id;
    cin >> name >> score >> sex >> id;
    students[name] = {score, id, sex};
    keep[score].insert(name);
  }
  int T;
  cin >> T;
  while (T--) {
    int pattern;
    cin >> pattern;
    if (pattern & 1) {
      string name;
      cin >> name;
      auto student = students[name];
      cout << student.score << ' ' << student.id << ' ' << student.sex << '\n';
    } else {
      int score;
      cin >> score;
      for (const string &name : keep[score]) {
        cout << name << '\n';
      }
    }
  }
}
