#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main()
{
  long long N, M;
  cin >> N >> M;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  vector<vector<double>> c(N+1, vector<double>(N+1));
  for (int i=0; i<=N; i++) {
    for (int j=0; j<i; j++) {
      double sum = 0;
      for (int k=j; k<i; k++) sum += a[k];
      c[j][i] = sum / (i-j);
    }
  }

  vector<vector<double>> dp(N+1, vector<double>(M+1, -INF));
  dp[0][0] = 0;

  for (int i=0; i<=N; i++) {
    for (int j=0; j<i; j++) {
      for (int k=1; k<=M; k++) {
        chmax(dp[i][k], dp[j][k-1] + c[j][i]);
      }
    }
  }

  cout << fixed << setprecision(10) << dp[N][M] << endl;
}
