#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[k] := 残りk個の石が残っているときに次の人を負けにできるか
 *
 * 石を取る数の種類は常に同じ
 * => 今のターンがどちらかは関係ない
 *
 * 小問題を元の問題に拡大したときにdp[K]が答えになるようにできる
 *
 * 勝ち筋が一つでもあれば、必ず勝つ。逆に一つもなければ負ける
 */
int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<bool> dp(K+1, false);
  for (int k=1; k<=K; k++) {
    for (int i=0; i<N; i++) {
      if (k-A[i] >= 0 && !dp[k-A[i]]) dp[k] = true;
    }
  }

  if (dp[K]) cout << "First" << endl;
  else cout << "Second" << endl;
}
