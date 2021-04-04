#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VP = vector<pair<int, int>>;
#define rep(i, a, b) for (auto i = (a); i != (b); ++i)
#define grep(i, u) for (auto i = gh[u]; i != -1; i = gn[i])
#define mem(x, v) memset(x, v, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(x))
#define SZ(V) (int)(V.size())
#define pb push_back
#define mp make_pair

constexpr int maxn = 10010;

bool is_prime[maxn];

int prime[maxn], last;

/**
 * 线性筛求素数
 * 具体可参考https://oi-wiki.org/math/sieve/
 */
void prime_select() {
  mem(is_prime, true);
  rep(i, 2, maxn) {
    if (is_prime[i]) prime[last++] = i;
    rep(j, 0, last) {
      if (i * prime[j] >= maxn) break;
      is_prime[i * prime[j]] = false;
      if (!(i % prime[j])) break;
    }
  }
}

/**
 * @param x 整数变量
 * @return 若x为素数,返回true,否则返回false
 */
bool check(int x) {
  if (x < maxn) return is_prime[x];
  rep(j, 0, last) {
    if (!(x % prime[j])) return false;
    if (prime[j] * prime[j] > x) break;
  }
  return true;
}

int bit[maxn], cnt;

/**
 * @param x 整数变量
 * @return 返回十进制下x翻转后的数字
 */
int rev(int x) {
  int ans = 0;
  cnt = 0;
  while (x) bit[cnt++] = x % 10, x /= 10;
  rep(i, 0, cnt) ans = ans * 10 + bit[i];
  return ans;
}

int pow10[9], ans[maxn], ans_size;

/**
 * 求出所有5~1e8以内的回文素数,由小到大存放在ans数组
 */
void generate() {
  ans_size = 0;
  ans[ans_size++] = 5;
  ans[ans_size++] = 7;
  ans[ans_size++] = 11;
  /// 预处理10的幂
  pow10[0] = 1;
  rep(i, 1, 9) pow10[i] = pow10[i - 1] * 10;
  int r = 10;
  rep(i, 2, 5) {
    int l = r;
    r *= 10;
    /// 求出由前i位确定的奇数长度的回文素数
    rep(j, l, r) {
      int p = j * pow10[i - 1] + rev(j / 10);
      if (check(p)) ans[ans_size++] = p;
    }
    /**
     * 求出由前i位确定的偶数长度的回文素数
     * 由于偶数长度的回文数均为11的倍数,故可删去
     */
    // rep(j, l, r) {
    //   int p = j * pow10[i] + rev(j);
    //   if (check(p)) ans[ans_size++] = p;
    // }
  }
}

int main() {
  prime_select();
  generate();
  int a, b;
  scanf("%d%d", &a, &b);
  /// 二分求出ans数组中属于[a,b]的数
  /// lower_bound和upper_bound用法可自行百度
  auto l = lower_bound(ans, ans + ans_size, a), r = upper_bound(ans, ans + ans_size, b);
  rep(iter, l, r) printf("%d\n", *iter);
}
