#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 998244353;

int main()
{
  long long N;
  cin >> N;

  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(N+1, vector<long long>(N, 0)));

  dp[0][0][0] = 1;
  for (long long i=0; i<N; i++) {
    for (long long k=0; k<N; k++) {
      for (long long j=0; j<N; j++) {
        int amari = (j+A[i]) % (k+1);
        dp[i+1][k+1][amari] += dp[i][k][j];
        dp[i+1][k+1][amari] %= MOD;

        dp[i+1][k][j] += dp[i][k][j];
        dp[i+1][k][j] %= MOD;
      }
    }
  }

  long long ans = 0;
  for (int k=1; k<=N; k++) {
    ans += dp[N][k][0];
    ans %= MOD;
  }
  cout << ans << endl;
}
