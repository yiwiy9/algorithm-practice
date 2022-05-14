#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

/**
 * https://atcoder.jp/contests/abc251/tasks/abc251_e
 * 問題を小さく分けられるときはDPを使う
 *
 * ・動物iに餌をあげるには、行動i-1 or 行動iを取る必要がある
 * ・問題は行動Nが行動1に影響を与えてしまう
 *   => 行動1を行う場合と行わない場合で固定する
 *   => 行動1を行う場合：行動Nを行わなかったときの最小値を見る
 *      行動1を行わない場合：行動Nを行ったときの最小値を見る
 */
int main()
{
  int N;
  cin >> N;

  vector<long long> A(N+1);
  for (int i=1; i<=N; i++) cin >> A[i];

  long long ans = INF;
  for (int j=0; j<=1; j++) {
    vector<vector<long long>> dp(N+1, vector<long long>(2, INF));
    if (j == 0) {
      dp[1][0] = 0;
      dp[1][1] = INF; // 選択不可能にする
    } else {
      dp[1][0] = INF; // 選択不可能にする
      dp[1][1] = A[1];
    }

    for (int i=2; i<=N; i++) {
      // iを選ばない場合
      chmin(dp[i][0], dp[i-1][1]);

      // iを選ぶ場合
      chmin(dp[i][1], dp[i-1][0] + A[i]);
      chmin(dp[i][1], dp[i-1][1] + A[i]);
    }

    if (j == 0) {
      chmin(ans, dp[N][1]);
    } else {
      chmin(ans, dp[N][0]);
      chmin(ans, dp[N][1]);
    }
  }

  cout << ans << endl;
}
