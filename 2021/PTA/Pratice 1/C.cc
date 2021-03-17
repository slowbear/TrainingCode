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

int f[11];

int number[11], id[10];

int main() {
  rep(i, 0, 11) {
    char ch;
    scanf("%c", &ch);
    f[i] = ch - '0';
  }
  rep(i, 0, 11) number[i] = f[i];
  sort(number, number + 11, greater<int>());
  int len = unique(number, number + 11) - number;
  printf("int[] arr = new int[]{");
  rep(i, 0, len) printf("%d%c", number[i], ",}"[i == len - 1]);
  printf(";\nint[] index = new int[]{");
  rep(i, 0, len) id[number[i]] = i;
  rep(i, 0, 11) printf("%d%c", id[f[i]], ",}"[i == 10]);
  printf(";\n");
}
