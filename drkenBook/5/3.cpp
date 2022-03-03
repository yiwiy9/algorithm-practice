#include <iostream>
#include <vector>
using namespace std;

// この解答、題意読み違え。総和Wにできる選び方の総数を計算している
int main()
{
  long long N, W;
  cin >> N >> W;
  vector<long long> a(N);
  for (long long i=0; i<N; i++) cin >> a[i];

  vector<vector<long long>> dp(N+1, vector<long long>(W+1));
  dp[0][0] = 1;

  for (long long i=0; i<N; i++) {
    for (long long w=0; w<=W; w++) {
      if (dp[i][w] == 0) continue;

      dp[i+1][w] += dp[i][w];
      if (w+a[i] <= W) {
        dp[i+1][w+a[i]] += dp[i][w];
      }
    }
  }

  cout << dp[N][W] << endl;
}
