#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

template<class T> bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> A(N+1);
  for (long long i=1; i<=N; i++) cin >> A[i];

  vector<vector<long long>> dp(N+1, vector<long long>(M+1, -INF));
  for (long long i=0; i<=N; i++) dp[i][0] = 0;

  for (long long i=1; i<=N; i++) {
    for (long long m=1; m<=M; m++) {
      chmax(dp[i][m], dp[i-1][m]);
      chmax(dp[i][m], dp[i-1][m-1] + (A[i] * m));
    }
  }

  cout << dp[N][M] << endl;
}
