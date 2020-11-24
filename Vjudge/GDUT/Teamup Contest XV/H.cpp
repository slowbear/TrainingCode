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

constexpr int maxn = 2e6 + 7;

inline int ord(char ch) {
  if (ch == '.') return 0;
  if (ch == '/') return 1;
  return ch - 'a' + 2;
}

inline char revord(int x) {
  if (!x) return '.';
  if (x == 1) return '/';
  return x - 2 + 'a';
}

struct FileTree {
  int go[28];
  bool is_directory;
  bool printed;
  int size, pwd, status;
} fs[maxn];

const char *flag = " +-";

int inode;

void add(int rt, const char *str, int size) {
  int len = strlen(str), last = 0;
  rep(i, 0, len) {
    if (!fs[rt].go[ord(str[i])]) fs[rt].go[ord(str[i])] = inode++;
    rt = fs[rt].go[ord(str[i])];
    if (str[i] == '/') {
      fs[rt].size += size;
      fs[rt].is_directory = true;
      fs[fs[rt].pwd = last].status = 1;
      last = rt;
    }
  }
}

void check_printed(int rt, int limit) {
  if (fs[rt].is_directory) {
    fs[rt].printed = fs[rt].size >= limit;
    if (fs[rt].printed) fs[fs[rt].pwd].status = 2;
  }
  rep(i, 0, 28) if (fs[rt].go[i]) check_printed(fs[rt].go[i], limit);
}

char ans[maxn];

int ans_last;

void print(int rt) {
  if (fs[rt].is_directory) {
    if (fs[rt].printed || fs[fs[rt].pwd].status == 2) {
      ans[ans_last] = '\0';
      printf("%c %s %d\n", flag[fs[rt].status], ans, fs[rt].size);
    }
  }
  rep(i, 0, 28) if (fs[rt].go[i]) {
    ans[ans_last++] = revord(i);
    print(fs[rt].go[i]);
    --ans_last;
  }
}

inline char *trim_after_slash(char *str) {
  int len = strlen(str);
  while (str[len - 1] != '/') str[--len] = '\0';
  return str;
}

char filename[maxn];

int filesize;

int main() {
  int n, rt = 0;
  scanf("%d", &n);
  inode = 1;
  while (n--) {
    scanf(" %s %d", filename, &filesize);
    auto path = trim_after_slash(filename);
    add(rt, path, filesize);
  }
  int limit;
  scanf("%d", &limit);
  check_printed(rt, limit);
  fs[1].printed = true;
  print(rt);
}
