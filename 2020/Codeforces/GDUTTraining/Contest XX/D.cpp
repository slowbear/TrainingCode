#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

struct Node {
  Node *lch, *rch;
  int key, size, priority;
  Node(int k) : lch(nullptr), rch(nullptr), key(k), size(1), priority(rand()) {}
};

void maintain(Node *rt) {
  rt->size = 1;
  if (rt->lch) rt->size += rt->lch->size;
  if (rt->rch) rt->size += rt->rch->size;
}

pair<Node *, Node *> split(Node *rt, int key) {
  if (rt) {
    if (key <= rt->key) {
      auto sub = split(rt->lch, key);
      rt->lch = sub.second;
      maintain(rt);
      return make_pair(sub.first, rt);
    } else {
      auto sub = split(rt->rch, key);
      rt->rch = sub.first;
      maintain(rt);
      return make_pair(rt, sub.second);
    }
  } else {
    return make_pair(nullptr, nullptr);
  }
}

Node *merge(Node *u, Node *v) {
  if (!u) return v;
  if (!v) return u;
  if (u->priority > v->priority) {
    u->rch = merge(u->rch, v);
    maintain(u);
    return u;
  } else {
    v->lch = merge(u, v->lch);
    maintain(v);
    return v;
  }
}

void insert(Node *(&rt), int key) {
  auto u = split(rt, key);
  u.first = merge(u.first, new Node(key));
  rt = merge(u.first, u.second);
}

constexpr int MAX_LEM = 201000;

char str[MAX_LEM];

int cnt[MAX_LEM];

int main() {
  srand(time(nullptr));
  int p, q;
  scanf("%d%d", &p, &q);
  scanf(" %s", str + 1);
  int len = strlen(str + 1);
  cnt[0] = 0;
  Node *treap = nullptr;
  long long ans = 0;
  for (int i = 1; i <= len; ++i) cnt[i] = cnt[i - 1] + (str[i] - '0');
  for (int i = 1; i <= len; ++i) {
    int f = q * cnt[i] - p * i;
    insert(treap, q * cnt[i - 1] - p * (i - 1));
    auto u = split(treap, f);
    if (u.first != nullptr) ans += u.first->size;
    treap = merge(u.first, u.second);
  }
  printf("%lld\n", ans);
}
