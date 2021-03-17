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

constexpr int maxn = 1e4 + 7;

double score[maxn];

int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  int single[10];
  rep(i, 0, n) {
    rep(j, 0, k) scanf("%d", &single[j]);
    double sum = accumulate(single, single + k, 0) - *max_element(single, single + k) -
                 *min_element(single, single + k);
    score[i] = sum / (k - 2);
  }
  sort(score, score + n, greater<double>());
  rev(i, 0, m) printf("%.3f%c", score[i], " \n"[!i]);
}
