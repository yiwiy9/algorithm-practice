#include <iostream>
#include <vector>
using namespace std;
const long long mod = 998244353;

/**
 * https://atcoder.jp/contests/abc248/tasks/abc248_c
 *
 * 問題の読み替え
 * M以下の数字をN個選んだ総和がK以下になる場合の数
 *
 * => dp[i][j] := M以下の数字をi個選んだ総和がjになる場合の数
 */
// int main()
// {
//   int N, M, K;
//   cin >> N >> M >> K;

//   vector<vector<long long>> dp(N+1, vector<long long>(K+1));

//   dp[0][0] = 1;
//   for (int i=0; i<N; i++) {
//     for (int j=0; j<K; j++) {
//       for (int m=1; m<=M; m++) {
//         if (j+m > K) continue;
//         dp[i+1][j+m] += dp[i][j];
//         dp[i+1][j+m] %= mod;
//       }
//     }
//   }

//   long long ans = 0;
//   for (int j=0; j<=K; j++) {
//     ans += dp[N][j];
//     ans %= mod;
//   }

//   cout << ans << endl;
// }

/**
 * O(NK) で解いてみましょう。（中級者向け）
 * dp[i+1] を更新する際に dp[i] の累積和を前計算しておくことで、遷移が O(1)
 */
int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  // S（左：閉区間、右：開区間）
  vector<vector<long long>> dp(N+1, vector<long long>(K+1)), S(N+1, vector<long long>(K+1));

  dp[0][0] = 1;

  for (int i=0; i<N; i++) {
    for (int j=1; j<=K; j++) {
      S[i][j] = S[i][j-1] + dp[i][j-1];
      S[i][j] %= mod;

      if (j-M > 0) {
        dp[i+1][j] = S[i][j] - S[i][j-M];
      } else {
        dp[i+1][j] = S[i][j] - S[i][0];
      }
      dp[i+1][j] += mod; // C++ 負の数のmodは負の数で出る => 割る数を足してあげる
      dp[i+1][j] %= mod;
    }
  }

  long long ans = 0;
  for (int j=0; j<=K; j++) {
    ans += dp[N][j];
    ans %= mod;
  }

  cout << ans << endl;
}
