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

constexpr int MAX_NUM = 10100;

int U[MAX_NUM], D[MAX_NUM], L[MAX_NUM], R[MAX_NUM];

int first[MAX_NUM], cnt[MAX_NUM], row[MAX_NUM], col[MAX_NUM], total;

void remove(int c) {
  L[R[c]] = L[c];
  R[L[c]] = R[c];
  for (int i = D[c]; i != c; i = D[i]) {
    for (int j = R[i]; j != i; j = R[j]) {
      U[D[j]] = U[j];
      D[U[j]] = D[j];
      --cnt[col[j]];
    }
  }
}

void recover(int c) {
  for (int i = U[c]; i != c; i = U[i]) {
    for (int j = L[i]; j != i; j = L[j]) {
      U[D[j]] = D[U[j]] = j;
      ++cnt[col[j]];
    }
  }
  R[L[c]] = L[R[c]] = c;
}

void build(int /*r */, int c) {
  rep(i, 0, c + 1) {
    L[i] = i - 1;
    R[i] = i + 1;
    U[i] = D[i] = i;
  }
  L[0] = c;
  R[c] = 0;
  mem(first, 0);
  mem(cnt, 0);
  total = c + 1;
}

void insert(int r, int c) {
  row[total] = r;
  col[total] = c;
  ++cnt[c];
  D[total] = D[c];
  U[D[c]] = total;
  U[total] = c;
  D[c] = total;
  if (first[r]) {
    L[total] = first[r];
    R[total] = R[first[r]];
    R[first[r]] = L[R[total]] = total;
  } else {
    first[r] = L[total] = R[total] = total;
  }
  ++total;
}

int ans[MAX_NUM], a[9][9];

bool dance(int dep) {
  if (!R[0]) {
    rep(i, 0, dep) printf("%d%c", ans[i], " \n"[i == dep - 1]);
    return true;
  }
  int x = R[0];
  for (int i = R[x]; i; i = R[i]) {
    if (cnt[i] < cnt[x]) x = i;
  }
  remove(x);
  for (int i = D[x]; i != x; i = D[i]) {
    ans[dep] = row[i];
    for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
    if (dance(dep + 1)) return true;
    for (int j = L[i]; j != i; j = L[j]) recover(col[j]);
  }
  recover(x);
  return false;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  build(n, m);
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    int x;
    scanf("%d", &x);
    if (x) insert(i, j);
  }
  if (!dance(0)) printf("No Solution!\n");
}
