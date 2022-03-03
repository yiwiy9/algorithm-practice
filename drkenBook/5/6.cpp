#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;
const long long ZERO = 0;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main()
{
  long long N, W;
  cin >> N >> W;
  vector<long long> a(N), m(N);
  for (long long i=0; i<N; i++) cin >> a[i] >> m[i];

  vector<vector<long long>> dp(N+1, vector<long long>(W+1, INF));
  dp[0][0] = 0;

  for (long long i=0; i<N; i++) {
    for (long long w=0; w<=W; w++) {
      if (dp[i][w] == INF) continue;

      chmin(dp[i+1][w], ZERO);
      if (w+a[i] <= W && dp[i][w] < m[i]) {
        chmin(dp[i][w+a[i]], dp[i][w] + 1);
      }
    }
  }

  if (dp[N][W] < INF) cout << "Yes" << endl;
  else cout << "No" << endl;
}
