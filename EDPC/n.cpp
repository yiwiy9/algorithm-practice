#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

/**
 * dp[i][j] := 区間i~jのスライムを１匹にしたときの最小コスト
 * 直前の状態は、dp[i][k] と dp[k][j] で表される
 * 合体にかかるコスト x+y は、区間i~jのスライムの総和s[i:j]で表される
 * よって遷移式は、chmin(dp[i][j], dp[i][k] + dp[k][j] + s[i:j])
 *
 * DPの更新順序を考える
 * k-i, j-k はいずれも j-i より小さい値になっていることがわかる
 * よって、j-i が小さい順にDPを更新していけばよい
 */
int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<vector<long long>> dp(N+1, vector<long long>(N+1, INF));
  vector<long long> S(N+1, 0);

  for (int i=0; i<N; i++) {
    dp[i][i+1] = 0;
    S[i+1] = S[i] + A[i];
  }

  for (int d=2; d<=N; d++) {
    for (int i=0; i+d<=N; i++) {
      for (int k=i+1; k<i+d; k++) {
        chmin(dp[i][i+d], dp[i][k] + dp[k][i+d] + S[i+d] - S[i]);
      }
    }
  }

  cout << dp[0][N] << endl;
}
