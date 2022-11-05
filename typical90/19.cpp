#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 30;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_s
 * https://twitter.com/e869120/status/1384638694162780166/photo/1
 * dp[i][j] := 区間i~jのAを全て選ばれたときの最小コスト
 * 遷移は以下の二つが考えられる
 * 1. 直前の状態が区間i+1~j-1が既に選ばれた状態
 *    => chmin(dp[i][j], dp[i+1][j-1] + abs(A[i]-A[j]))
 * 2. それ以外（既にi,jが選ばれている区間がそれぞれある）
 *    => chmin(dp[i][j], dp[i][k] + dp[k+1][j])
 */
int main() {
  int N;
  cin >> N;
  vector<int> A(2*N);
  for (int i=0; i<2*N; i++) cin >> A[i];

  vector<vector<int>> dp(2*N, vector<int>(2*N, inf));
  for (int i=0; i<2*N; i++) {
    dp[i][i] = 0;
    if (i+1<2*N) dp[i][i+1] = abs(A[i]-A[i+1]);
  }

  for (int d=1; d<N; d++) {
    int dd = 2*d+1;
    for (int i=0; i<2*N-dd; i++) {
      int j = i+dd;
      chmin(dp[i][j], dp[i+1][j-1] + abs(A[i]-A[j]));

      for (int k=i+1; k<j; k+=2) {
        chmin(dp[i][j], dp[i][k] + dp[k+1][j]);
      }
    }
  }

  cout << dp[0][2*N-1] << endl;
}
