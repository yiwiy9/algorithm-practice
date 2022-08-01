#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

/**
 * https://atcoder.jp/contests/abc262/tasks/abc262_d
 * 割る数を固定しないと、余りは保存しない
 * => i個選ぶとしてループして、その中でdp
 */
int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = 0;
  for (int i=1; i<=N; i++) {
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(i+1, vector<int>(i, 0)));
    dp[0][0][0] = 1;

    for (int j=0; j<N; j++) {
      for (int k=0; k<=i; k++) {
        for (int l=0; l<i; l++) {
          if (k+1 <= i) {
            int amari = (l+A[j]) % i;
            dp[j+1][k+1][amari] += dp[j][k][l];
            dp[j+1][k+1][amari] %= MOD;
          }

          dp[j+1][k][l] += dp[j][k][l];
          dp[j+1][k][l] %= MOD;
        }
      }
    }

    ans += dp[N][i][0];
    ans %= MOD;
  }

  cout << ans << endl;
}
