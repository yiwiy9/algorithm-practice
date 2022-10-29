#include <iostream>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

/**
 * テーブルを作る前処理
 * a^(-1) ≡ -(p%a)^(-1) * (p/a)   (mod.p)
 */
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = (- inv[MOD%i] * (MOD / i)) % MOD + MOD; // c++の場合、負の数の余りが負になるので、割る数を足して正にする
      finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

/**
 * 二項係数計算
 * nCk = n!/(k!(n-k)!) = (n!) * (k!)^(-1) * ((n-k))!)^(-1)
 *
 * 参考：https://drken1215.hatenablog.com/entry/2018/06/08/210000
 *
 * 使用可能場面
 *   * 1 ≤ k ≤ n ≤ 10^7
 *   * pは素数 かつ p > n
 */
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_o
 * https://twitter.com/e869120/status/1382827276673306624/photo/1
 *
 * => 考察しきって、{N-(k-1)(a-1)}Ca を求めれば良い
*/
int main() {
  int N;
  cin >> N;

  // 前処理
  COMinit();

  // 調和級数（O(NlogN)）
  for (int k=1; k<=N; k++) {
    long long ans = 0;

    // 「N 個中何個選ぶか」を全探索
    // そもそも K が大きいと 1 個か 2 個しか選べないので、そこに着目する
    for (int a=1; a<=N/k + 1; a++) {
      ans += COM(N-(k-1)*(a-1), a);
      ans %= MOD;
    }

    cout << ans << endl;
  }
}
