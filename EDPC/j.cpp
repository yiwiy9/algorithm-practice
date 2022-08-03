#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int N;
vector<vector<vector<double>>> dp;
double rec(double one, double two, double three)
{
  if (dp[one][two][three] != -1) return dp[one][two][three];

  if (one == 0 && two == 0 && three == 0) return dp[one][two][three] = 0;

  double div = 1-(N-(one+two+three))/N;
  double next_ex = 1/div;

  if (one > 0) {
    next_ex += rec(one-1, two, three)*one/N/div;
  }
  if (two > 0) {
    next_ex += rec(one+1, two-1, three)*two/N/div;
  }
  if (three > 0) {
    next_ex += rec(one, two+1, three-1)*three/N/div;
  }

  return dp[one][two][three] = next_ex;
}

/**
 * 確率DP / 期待値DP
 * https://compro.tsutaj.com//archive/180220_probability_dp.pdf
 *
 * 期待値を再帰的に足し合わせていく
 * 今の期待値 = Σ(次の状態の期待値 * それが起こる確率) + 1
 * => dp[one][two][three]
 *    = 1
 *      + dp[one-1][two][three]*(1個の皿が選ばれる確率)
 *      + dp[one+1][two-1][three]*(2個の皿が選ばれる確率)
 *      + dp[one][two+1][three-1]*(3個の皿が選ばれる確率)
 *      + dp[one][two][three]*(0個の皿が選ばれる確率)      ← これだと遷移できないので、式変形する
 *
 * => dp[one][two][three]
 *    = 1/(1-0個の皿が選ばれる確率)
 *      + dp[one-1][two][three]*(1個の皿が選ばれる確率)/(1-0個の皿が選ばれる確率)
 *      + dp[one+1][two-1][three]*(2個の皿が選ばれる確率)/(1-0個の皿が選ばれる確率)
 *      + dp[one][two+1][three-1]*(3個の皿が選ばれる確率)/(1-0個の皿が選ばれる確率)
 *
 * 今回は使わないTips
 * https://drken1215.hatenablog.com/entry/2019/03/23/175300
 * 確率 p で成功するミッションを成功するまでトライし続けたとき、トライすることになる回数の期待値は 1/p である
 */
int main()
{
  cin >> N;

  vector<double> C(4);
  for (int i=0; i<N; i++) {
    int a;
    cin >> a;
    C[a]++;
  }

  dp.assign(N+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));

  double ans = rec(C[1], C[2], C[3]);
  cout << fixed << setprecision(10) << ans << endl;
}
