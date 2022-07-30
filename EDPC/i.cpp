#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<double> P(N);
  for (int i=0; i<N; i++) cin >> P[i];

  vector<vector<double>> dp(N+1, vector<double>(N+1, 0));

  dp[0][0] = 1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      dp[i+1][j+1] += dp[i][j] * P[i];
      dp[i+1][j] += dp[i][j] * (1 - P[i]);
    }
  }

  double ans = 0;
  int M = N/2 + 1;
  for (int j=M; j<=N; j++) ans += dp[N][j];
  cout << fixed << setprecision(10) << ans << endl;
}
