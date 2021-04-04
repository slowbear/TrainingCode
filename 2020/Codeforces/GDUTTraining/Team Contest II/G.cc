#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int MAX_N = 101000;

struct Graph {
  struct Edge {
    int v, color, next;
  };
  int head[MAX_N];
  vector<Edge> edges;
  Graph() : edges() { memset(head, -1, sizeof(head)); }
  void add(int u, int v, int color) {
    edges.push_back({v, color, head[u]});
    head[u] = edges.size() - 1;
  }
};

Graph f, g;

bool reach[MAX_N];

void bfs(int s, const Graph &g) {
  queue<int> que;
  que.push(s);
  memset(reach, 0, sizeof(reach));
  reach[s] = true;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = g.head[u]; i != -1; i = g.edges[i].next) {
      int v = g.edges[i].v;
      if (!reach[v]) {
        reach[v] = true;
        que.push(v);
      }
    }
  }
}

bool vis[MAX_N];

int ans[MAX_N], last;

bool find_ans(int s, int t, const Graph &g) {
  last = 0;
  memset(vis, 0, sizeof(vis));
  vis[s] = true;
  while (s != t) {
    int min_color = INT32_MAX, v = -1;
    for (int i = g.head[s]; i != -1; i = g.edges[i].next) {
      int u = g.edges[i].v, color = g.edges[i].color;
      if (!reach[u]) continue;
      if (color < min_color) {
        min_color = color;
        v = u;
      }
    }
    if (vis[v]) return false;
    s = v;
    vis[s] = true;
    ans[last++] = min_color;
  }
  return true;
}

int main() {
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 0; i < m; ++i) {
    int u, v, color;
    scanf("%d%d%d", &u, &v, &color);
    f.add(u, v, color);
    g.add(v, u, color);
  }
  bfs(t, g);
  if (!reach[s]) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  if (find_ans(s, t, f)) {
    for (int i = 0; i < last; ++i) printf("%d ", ans[i]);
    printf("\n");
  } else {
    printf("TOO LONG\n");
  }
}
