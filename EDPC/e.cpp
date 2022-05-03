#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}
template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  int N, W;
  cin >> N >> W;

  vector<int> w(N), v(N);
  for (int i=0; i<N; i++) {
    cin >> w[i];
    cin >> v[i];
  }

  vector<vector<long long>> dp(N+1, vector<long long>(100001, INF));

  dp[0][0] = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<100001; j++) {
      if (dp[i][j] == INF) continue;

      if (dp[i][j] + w[i] <= W) {
        // i番目を選ぶ場合
        chmin(dp[i+1][j + v[i]], dp[i][j] + w[i]);
      }
      // i番目を選ばない場合
      chmin(dp[i+1][j], dp[i][j]);
    }
  }

  for (int j=100000; j>=0; j--) {
    if (dp[N][j] != INF) {
      cout << j << endl;
      break;
    }
  }
}
