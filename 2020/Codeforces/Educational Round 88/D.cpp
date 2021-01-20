#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

constexpr int MAX_N = 201000;

int a[MAX_N];

int ex[MAX_N][2], prefix[MAX_N], st_prefix_min[MAX_N][20], st_prefix_max[MAX_N][20];

int log_2[MAX_N];

int get_max(int l, int r) {
  int sz = log_2[r - l + 1];
  return max(st_prefix_max[r][sz], st_prefix_max[l + (1 << sz) - 1][sz]);
}

int get_min(int l, int r) {
  int sz = log_2[r - l + 1];
  return min(st_prefix_min[r][sz], st_prefix_min[l + (1 << sz) - 1][sz]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  prefix[0] = 0;
  log_2[1] = 0;
  for (int i = 2; i < MAX_N; ++i) log_2[i] = log_2[i / 2] + 1;
  for (int j = 0; j < 20; ++j) st_prefix_max[0][j] = st_prefix_min[0][j] = 0;
  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1] + a[i];
    st_prefix_max[i][0] = prefix[i];
    st_prefix_min[i][0] = prefix[i];
    for (int j = 1; (j < 20) && (i >= (1 << (j - 1))); ++j) {
      st_prefix_max[i][j] = max(st_prefix_max[i][j - 1], st_prefix_max[i - (1 << (j - 1))][j - 1]);
      st_prefix_min[i][j] = min(st_prefix_min[i][j - 1], st_prefix_min[i - (1 << (j - 1))][j - 1]);
    }
  }
  stack<int> st;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty()) {
      int u = st.top();
      if (a[i] >= a[u])
        st.pop();
      else
        break;
    }
    ex[i][0] = st.empty() ? 0 : st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n; i > 0; --i) {
    while (!st.empty()) {
      int u = st.top();
      if (a[i] >= a[u])
        st.pop();
      else
        break;
    }
    ex[i][1] = st.empty() ? n + 1 : st.top();
    st.push(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = ex[i][0], r = ex[i][1];
    int x = get_max(i, r - 1);
    int y = get_min(l, i - 1);
    ans = max(ans, x - y - a[i]);
  }
  printf("%d\n", ans);
}
