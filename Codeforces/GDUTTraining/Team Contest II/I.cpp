//! Wrong answer on test 8
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int MAX_N = 501;

struct Graph {
  struct Edge {
    int u, v, w, next;
  };
  int head[MAX_N];
  vector<Edge> edges;
  Graph() : edges() { memset(head, -1, sizeof(head)); }
  void add(int u, int v, int w) {
    edges.push_back({u, v, w, head[u]});
    head[u] = edges.size() - 1;
  }
};

bool vis[MAX_N];

Graph generate_tree(int u, const Graph &g) {
  queue<int> que;
  Graph graph;
  memset(vis, 0, sizeof(vis));
  vis[u] = true;
  que.push(u);
  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    for (int i = g.head[u]; i != -1; i = g.edges[i].next) {
      int v = g.edges[i].v, w = g.edges[i].w;
      if (!vis[v]) {
        vis[v] = true;
        graph.add(u, v, w);
        que.push(v);
      }
    }
  }
  return graph;
}

long long dis[MAX_N];

void dfs(int u, const Graph &g) {
  dis[u] = 0;
  for (int i = g.head[u]; i != -1; i = g.edges[i].next) {
    int v = g.edges[i].v, w = g.edges[i].w;
    dfs(v, g);
    dis[u] = max(dis[u], dis[v] + w);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Graph origin;
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    origin.add(u, v, w);
    origin.add(v, u, w);
  }
  long long ans = INT64_MAX;
  Graph ans_tree;
  for (int rt = 1; rt <= n; ++rt) {
    auto tree = generate_tree(rt, origin);
    dfs(rt, tree);
    vector<long long> candidate;
    long long d = dis[rt];
    for (int i = tree.head[rt]; i != -1; i = tree.edges[i].next) {
      int v = tree.edges[i].v, w = tree.edges[i].w;
      candidate.push_back(dis[v] + w);
    }
    if (candidate.size() >= 2) {
      sort(candidate.begin(), candidate.end());
      d = candidate[candidate.size() - 1] + candidate[candidate.size() - 2];
    }
    if (d < ans) {
      ans = d;
      ans_tree = tree;
    }
  }
  printf("%lld\n", ans);
  for (auto edge : ans_tree.edges) printf("%d %d\n", edge.u, edge.v);
}
