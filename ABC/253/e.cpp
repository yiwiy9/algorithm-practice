#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  // S（左：閉区間、右：開区間）
  vector<vector<long long>> dp(N+1, vector<long long>(M+1)), S(N+1, vector<long long>(M+1));

  dp[0][0] = 1;

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      S[i][j] = S[i][j-1] + dp[i][j-1];
      S[i][j] %= mod;

      if (j+K > M) {
        dp[i][j] = S[i-1][M] - S[i-1][j];
      } else {
        dp[i][j] = S[i-1][j+K] - S[i-1][j];
      }
      dp[i][j] += mod;
      dp[i][j] %= mod;

      if (j-K < 0) {
        dp[i][j] = S[i-1][j] - S[i-1][0];
      } else {
        dp[i][j] = S[i-1][j] - S[i-1][j-M];
      }
      dp[i][j] += mod;
      dp[i][j] %= mod;
    }
  }

  long long ans = 0;
  for (int j=0; j<=K; j++) {
    ans += dp[N][j];
    ans %= mod;
  }

  cout << ans << endl;
}
