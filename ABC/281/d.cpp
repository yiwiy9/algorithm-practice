#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  long long N, K, D;
  cin >> N >> K >> D;

  vector<long long> A(N);
  for (long long i=0; i<N; i++) cin >> A[i];

  vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(K+1, vector<long long>(D, -1)));
  for (int d=0; d<D; d++) dp[0][0][d] = 0;

  for (long long i=0; i<N; i++) {
    for (long long k=0; k<=K; k++) {
      for (long long d=0; d<D; d++) {
        if (dp[i][k][d] == -1) continue;

        // 選ぶ
        long long next_num = dp[i][k][d] + A[i];
        if (k+1 <= K) chmax(dp[i+1][k+1][next_num%D], next_num);

        // 選ばない
        chmax(dp[i+1][k][dp[i][k][d]%D], dp[i][k][d]);
      }
    }
  }

  cout << dp[N][K][0] << endl;
}
