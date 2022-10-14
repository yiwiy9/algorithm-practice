#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_e
 * https://twitter.com/e869120/status/1378527948563615746
*/

/**
 * 小課題１
 * 余りを持って桁DP
 *
 * dp[上からの何桁目(i)][現時点でのBで割った余り(j)] = 通り数
 * => dp[N][0] が答えになる
 *
 * 遷移式: dp[i+1][(10*j + c[k]) % B] += dp[i][j]
*/
int main()
{
  long long N;
  int B, K;
  cin >> N >> B >> K;

  vector<int> c(K);
  for (int k=0; k<K; k++) cin >> c[k];

  vector<vector<long long>> dp(N+1, vector<long long>(B, 0));
  dp[0][0] = 1;

  for (long long i=0; i<N; i++) {
    for (int j=0; j<B; j++) {
      for (int k=0; k<K; k++) {
        int next_mod = (10*j + c[k]) % B;
        dp[i+1][next_mod] += dp[i][j];
        dp[i+1][next_mod] %= MOD;
      }
    }
  }

  cout << dp[N][0] << endl;
}
