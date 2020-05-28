#error unfinished
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

constexpr int MAX_N = 501000;

long long prefix[MAX_N];

bool flag[MAX_N];

int main() {
  int n;
  scanf("%d", &n);
  prefix[0] = 0LL;
  for (int i = 1; i <= (n + 1) / 2; ++i) {
    int a;
    scanf("%d", &a);
    prefix[i] = prefix[i - 1] + a;
  }
  int a;
  scanf("%d", &a);
  for (int i = (n + 3) / 2; i <= n; ++i) prefix[i] = prefix[i - 1] + a;
  stack<int> st;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty()) {
      int u = st.top();
      if (prefix[i] > prefix[u])
        st.pop();
      else
        break;
    }
  }
}
