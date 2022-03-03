#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

/**
 * dp[i][j] ← 区間i~jのスライムを１匹にしたときの最小コスト
 * 直前の状態は、dp[i][k] と dp[k][j] で表される
 * 合体にかかるコスト x+y は、区間i~jのスライムの総和s[i:j]で表される
 * よって遷移式は、chmin(dp[i][j], dp[i][k] + dp[k][j] + s[i:j])
 *
 * DPの更新順序を考える
 * k-i, j-k はいずれも j-i より小さい値になっていることがわかる
 * よって、j-i が小さい順にDPを更新していけばよい
 *
 * 累積和について
 * https://qiita.com/drken/items/56a6b68edef8fc605821
 */
int main()
{
  long long N;
  cin >> N;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  // 累積和をとる
  vector<long long> S(N+1, 0);
  for (int i=0; i<N; i++) S[i+1] = S[i] + a[i];

  // DP（左：閉区間、右：開区間）
  vector<vector<long long>> dp(N+1, vector<long long>(N+1, INF));

  // 初期条件（区間の大きさが0の場合、コストも0）
  for (int i = 0; i < N; i++) dp[i][i+1] = 0;

  // 更新（区間の大きさが1の場合から増やしていく）
  for (int interval = 2; interval <= N; interval++) {
      for (int i = 0; i + interval <= N; i++) {
          int j = i + interval;

          // dp[i][j] を更新する
          for (int k = i+1; k < j; k++) {
              chmin(dp[i][j], dp[i][k] + dp[k][j] + S[j]-S[i]);
          }
      }
  }

  cout << dp[0][N] << endl;
}
