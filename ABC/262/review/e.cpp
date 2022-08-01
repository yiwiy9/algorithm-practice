#include <iostream>
#include <vector>
using namespace std;

const int MAX = 510000;
const int MOD = 998244353;

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
 * https://atcoder.jp/contests/abc262/tasks/abc262_e
 * 赤く塗った頂点の次数の総和を S、赤く塗られた頂点どうしを結ぶ辺の本数を R、異なる色の頂点を結ぶ辺の本数を D とおくと
 * => S = 2R+D（赤く塗られた頂点どうしを結ぶ辺が２回カウントされるため)
 * => S ≡ D (mod 2)
 * => Dが偶数であることが条件なので、Sが偶数である場合を考える
 * => つまり、赤く塗った頂点のうち、次数が奇数である頂点が偶数個であれば良い
 */
int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> deg(N);
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
  }

  int odd_deg_cnt = 0;
  for (int v=0; v<N; v++) {
    if (deg[v] % 2 == 1) odd_deg_cnt++;
  }
  int even_deg_cnt = N - odd_deg_cnt;

  COMinit();

  long long ans = 0;
  for (int i=0; i<=K; i+=2) {
    if (i > odd_deg_cnt || K-i > even_deg_cnt) continue;
    ans += (COM(odd_deg_cnt, i) * COM(even_deg_cnt, K-i)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
