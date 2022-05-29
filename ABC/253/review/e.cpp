#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

/**
 * https://atcoder.jp/contests/abc253/tasks/abc253_e
 *
 * dp[i][j] := A の先頭から i 項を決めて、i 項目が j であるような場合の数
 * => dp[i+1][j] = (dp[i][1]+…+dp[i][j−K]) + (dp[i][j+K]+…+dp[i][M])
 */
int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  // S（左：閉区間、右：開区間）
  vector<vector<long long>> dp(N, vector<long long>(M+1)), S(N, vector<long long>(M+1));

  for (int j=1; j<=M; j++) {
    dp[0][j] = 1;
    S[0][j] = S[0][j-1] + dp[0][j];
  }

  for (int i=1; i<N; i++) {
    for (int j=1; j<=M; j++) {
      if (j+K <= M) {
        dp[i][j] += S[i-1][M] - S[i-1][j+K-1];
        dp[i][j] += mod;
        dp[i][j] %= mod;
      }

      if (j-K >= 1) {
        dp[i][j] += S[i-1][j-K] - S[i-1][0];
        dp[i][j] += mod;
        dp[i][j] %= mod;
      }

      if (K == 0) {
        dp[i][j] -= dp[i-1][j]; // 重複して足してる分を引く
        dp[i][j] += mod;
        dp[i][j] %= mod;
      }

      S[i][j] = S[i][j-1] + dp[i][j];
      S[i][j] += mod;
      S[i][j] %= mod;
    }
  }

  long long ans = 0;
  for (int j=1; j<=M; j++) {
    ans += dp[N-1][j];
    ans %= mod;
  }

  cout << ans << endl;
}
