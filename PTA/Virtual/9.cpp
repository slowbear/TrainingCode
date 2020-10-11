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

constexpr int maxkey = 101000;

int nxt[maxkey], key[maxkey];

unordered_set<int> f;

VI v1, v2;

void print(const VI &vec) {
  if (!vec.size()) return;
  printf("%05d %d ", vec[0], key[vec[0]]);
  rep(i, 1, vec.size()) printf("%05d\n%05d %d ", vec[i], vec[i], key[vec[i]]);
  printf("-1\n");
}

int main() {
  int n, hd;
  scanf("%d%d", &hd, &n);
  rep(i, 0, n) {
    int id, k, suf;
    scanf("%d%d%d", &id, &k, &suf);
    nxt[id] = suf;
    key[id] = k;
  }
  while (hd != -1) {
    if (f.count(abs(key[hd]))) {
      v2.pb(hd);
    } else {
      v1.pb(hd);
      f.insert(abs(key[hd]));
    }
    hd = nxt[hd];
  }
  print(v1);
  print(v2);
}
