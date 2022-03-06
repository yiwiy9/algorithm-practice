#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;

/**
 * https://atcoder.jp/contests/abc242/tasks/abc242_c
 *
 * コンビネーションで定式化できると思って詰んだ
 * → 漸化式を探って、DPできないかという視点を持つ
 *   Nの小さいところで、遷移の関係性を探る
 */
int main()
{
  int N;
  cin >> N;

  vector<vector<int>> dp(N, vector<int>(9));
  for (int k=0; k<9; k++) dp[0][k] = 1;

  for (int i=0; i<N-1; i++) {
    for (int k=0; k<9; k++) {
      if (k-1 >= 0) {
        dp[i+1][k-1] += dp[i][k];
        dp[i+1][k-1] %= mod;
      }
      dp[i+1][k] += dp[i][k];
      dp[i+1][k] %= mod;
      if (k+1 < 9) {
        dp[i+1][k+1] += dp[i][k];
        dp[i+1][k+1] %= mod;
      }
    }
  }

  int ans = 0;
  for (int k=0; k<9; k++) {
    ans += dp[N-1][k];
    ans %= mod;
  }
  cout << ans << endl;
}
