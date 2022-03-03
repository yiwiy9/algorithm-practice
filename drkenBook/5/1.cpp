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
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N); // 自然数とする
  for (int i=0; i<N; i++) cin >> a[i] >> b[i] >> c[i];

  vector<vector<int>> dp(N, vector<int>(3));
  for (int i=0; i<N; i++) {
    if (i==0) {
      dp[i][1] = a[i];
      dp[i][2] = b[i];
      dp[i][3] = c[i];
      continue;
    }
    chmax(dp[i][1], dp[i-1][2] + a[i]);
    chmax(dp[i][1], dp[i-1][3] + a[i]);

    chmax(dp[i][2], dp[i-1][1] + b[i]);
    chmax(dp[i][2], dp[i-1][3] + b[i]);

    chmax(dp[i][3], dp[i-1][1] + c[i]);
    chmax(dp[i][3], dp[i-1][2] + c[i]);
  }

  int max = 0;
  for (auto happiness : dp[N-1]) {
    chmax(max, happiness);
  }
  cout << max << endl;
}
