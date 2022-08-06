#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL<<60;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * dp[i][j] := 先頭要素がi番目、末尾要素がj番目のときに互いに最大得点を取ろうとした時の得点差
 */
int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<vector<long long>> dp(N, vector<long long>(N, -INF));

  for (int j=0; j<N; j++) dp[j][j] = A[j];

  for (int i=1; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (j+i >= N) continue;
      chmax(dp[j][j+i], A[j+i] - dp[j][j+i-1]);
      chmax(dp[j][j+i], A[j] - dp[j+1][j+i]);
    }
  }

  cout << dp[0][N-1] << endl;
}
