#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main()
{
  long long N, W, k;
  cin >> N >> W >> k;
  vector<long long> a(N);
  for (long long i=0; i<N; i++) cin >> a[i];

  vector<vector<long long>> dp(N+1, vector<long long>(W+1, INF));
  dp[0][0] = 0;

  for (long long i=0; i<N; i++) {
    for (long long w=0; w<=W; w++) {
      if (dp[i][w] == INF) continue;

      chmin(dp[i+1][w], dp[i][w]);
      if (w+a[i] <= W) {
        chmin(dp[i+1][w+a[i]], dp[i][w]+1);
      }
    }
  }

  if (dp[N][W] <= k) cout << "Yes" << endl;
  else cout << "No" << endl;
}
