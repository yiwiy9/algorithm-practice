#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

/**
 * https://atcoder.jp/contests/abc261/tasks/abc261_d
 *
 * DPは未来が不確定だと使えない
 * → 未来を確定できる方法を考察する
 * → i回目のコイントスが終わった時点でのカウンタの数値Cが分かっていれば、
 *   i+1回目からN回目までのコイントスで得られるお金の最大値は(カウンタの数字がCとなるような出方である限り)
 *   1回目からi回目のコインの表裏の出方によらない
 * → 残り回数とその時点でのカウンタがわかっていれば、未来は決まる
 *
 * → よって、「i回目までコイントスをやって」、「現在のカウンタの数値がjである」ような条件の下で
 *   1回目からi回目までで得られる金額の最大値を更新していけばよい
 */
int main()
{
  long long N, M;
  cin >> N >> M;

  vector<long long> X(N+1);
  for (int i=1; i<=N; i++) cin >> X[i];

  vector<long long> B(N+1);
  for (int i=0; i<M; i++) {
    long long c, y;
    cin >> c >> y;
    B[c] = y;
  }

  vector<vector<long long>> dp(N+1, vector<long long>(N+1, -INF));
  dp[0][0] = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++) {
      // 表が出る場合
      chmax(dp[i+1][j+1], dp[i][j] + X[i+1] + B[j+1]);

      // 裏が出る場合
      chmax(dp[i+1][0], dp[i][j]);
    }
  }

  long long ans = 0;
  for (int j=1; j<N+1; j++) {
    chmax(ans, dp[N][j]);
  }
  cout << ans << endl;
}
