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
  D[c] = total;
  U[total] = c;
  if (first[r]) {
    L[total] = first[r];
    R[total] = R[first[r]];
    R[first[r]] = L[R[total]] = total;
  } else {
    first[r] = L[total] = R[total] = total;
  }
  ++total;
}

constexpr int rk[9][9] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 7, 7, 7, 7, 7, 7, 7, 6},  {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6}, {6, 7, 8, 9, 10, 9, 8, 7, 6}, {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6}, {6, 7, 7, 7, 7, 7, 7, 7, 6},  {6, 6, 6, 6, 6, 6, 6, 6, 6},
};

int ans[MAX_NUM], a[9][9], score;

void choose(int row) {
  int val = row % 9;
  if (!val) val = 9;
  row = (row - val) / 9;
  a[row / 9][row % 9] = val;
}

void dance(int dep) {
  if (!R[0]) {
    rep(i, 0, dep) choose(ans[i]);
    int sum = 0;
    rep(i, 0, 9) rep(j, 0, 9) sum += rk[i][j] * a[i][j];
    if (sum > score) score = sum;
    return;
  }
  int x = R[0];
  for (int i = R[x]; i; i = R[i]) {
    if (cnt[i] < cnt[x]) x = i;
  }
  remove(x);
  for (int i = D[x]; i != x; i = D[i]) {
    ans[dep] = row[i];
    for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
    dance(dep + 1);
    for (int j = L[i]; j != i; j = L[j]) recover(col[j]);
  }
  recover(x);
}

inline int get_block(int x, int y) {
  x /= 3;
  y /= 3;
  return 3 * x + y;
}

int main() {
  rep(i, 0, 9) rep(j, 0, 9) scanf("%d", &a[i][j]);
  build(729, 324);
  rep(i, 0, 9) rep(j, 0, 9) {
    rep(x, 1, 10) {
      if (!a[i][j] || (a[i][j] == x)) {
        insert(81 * i + 9 * j + x, 9 * i + x);
        insert(81 * i + 9 * j + x, 9 * j + 81 + x);
        insert(81 * i + 9 * j + x, 9 * get_block(i, j) + 162 + x);
        insert(81 * i + 9 * j + x, 9 * i + j + 244);
      }
    }
  }
  score = -1;
  dance(0);
  printf("%d\n", score);
}
