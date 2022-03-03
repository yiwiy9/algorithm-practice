#include <iostream>
#include <vector>
using namespace std;

int main()
{
  long long N, W;
  cin >> N >> W;
  vector<long long> a(N);
  for (long long i=0; i<N; i++) cin >> a[i];

  vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
  dp[0][0] = true;

  for (long long i=0; i<N; i++) {
    for (long long w=0; w<=W; w++) {
      if (!dp[i][w]) continue;

      dp[i+1][w] = true;
      if (w+a[i] <= W) {
        dp[i][w+a[i]] = true;
      }
    }
  }

  if (dp[N][W]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
