#include <iostream>
#include <vector>
using namespace std;

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

  vector<vector<long long>> dp(N+1, vector<long long>(W+1));

  for (int i=0; i<N; i++) {
    for (int j=0; j<=W; j++) {
      if (j + w[i] <= W) {
        // i番目を選ぶ場合
        chmax(dp[i+1][j + w[i]], dp[i][j] + v[i]);
      }
      // i番目を選ばない場合
      chmax(dp[i+1][j], dp[i][j]);
    }
  }

  cout << dp[N][W] << endl;
}
