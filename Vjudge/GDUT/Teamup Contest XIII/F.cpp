// Code by Wile
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Piii = pair<Pii, int>;
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

char g[4010][6010];
int n, m, sx, sy, tx, ty;
int len[4010], vis[4010][6010];
int dirx[6] = {-2, -4, -2, 2, 4, 2};
int diry[6] = {-6, 0, 6, 6, 0, -6};

int slove() {
  queue<Piii> q;
  rep(i, 0, n + 1) rep(j, 0, m + 1) vis[i][j] = 0;
  q.push(Piii(Pii(sx, sy), 1));
  vis[sx][sy] = 1;
  while (!q.empty()) {
    Piii u = q.front();
    q.pop();
    int x = u.first.first, y = u.first.second;
    int dis = u.second;

    // printf("%d %d %d\n", x, y, dis);

    for (int i = 0; i < 6; i++) {
      int nx = x + dirx[i], ny = y + diry[i];
      // if (x == sx && y == sy) printf("%d %d %d\n", nx, ny, dis);
      int midx = (x + nx + 2) / 2, midy = (y + ny + 2) / 2;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[midx - 1][midy - 1] == ' ' && !vis[nx][ny]) {
        q.push(Piii(Pii(nx, ny), dis + 1));
        vis[nx][ny] = dis + 1;
        if (nx == tx && ny == ty) {
          return dis + 1;
        }
      }
    }
  }

  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int r, c;
    scanf("%d%d", &r, &c);
    n = 4 * r + 3;
    m = 6 * c + 3;
    sx = sy = tx = ty = 0;
    scanf("\n");
    rep(i, 0, n) fgets(g[i], sizeof(g[i]), stdin);
    rep(i, 0, n) {
      len[i] = strlen(g[i]);
      // printf("%d\n%s\n", i, g[i]);
      rep(j, 0, len[i]) {
        if (g[i][j] == 'S')
          sx = i, sy = j;
        else if (g[i][j] == 'T')
          tx = i, ty = j;
      }
    }
    // printf("%d %d %d %d\n", sx, sy, tx, ty);

    printf("%d\n", slove());
  }
}
