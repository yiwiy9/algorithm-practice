#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

/**
 * dp[i][j] := i人の子供でj個の飴を分ける場合の数
 *
 * 累積和で遷移を高速化する(右側が開区間 = 含まれないことに注意)
 * S[i][j+1] = dp[i][0] + ... + dp[i][j]
 * S[i][j+1] - S[i][k] = dp[i][j] + ... + dp[i][k]
 */
int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<vector<long long>> dp(N+1, vector<long long>(K+1, 0)), S(N+1, vector<long long>(K+1+1));

  dp[0][0] = 1;

  for (int i=0; i<N; i++) {
    for (int j=1; j<=K+1; j++) {
      S[i][j] = S[i][j-1] + dp[i][j-1];
      S[i][j] %= MOD;
    }
    for (int j=0; j<=K; j++) {
      if (j-A[i] > 0) {
        dp[i+1][j] = S[i][j+1] - S[i][j-A[i]];
      } else {
        dp[i+1][j] = S[i][j+1] - S[i][0];
      }
      dp[i+1][j] += MOD;
      dp[i+1][j] %= MOD;
    }
  }

  cout << dp[N][K] << endl;
}
