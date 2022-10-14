#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_f
 * https://twitter.com/e869120/status/1379202843622576130/photo/1
 *
 * 辞書順最小は前から貪欲
 * => 前処理を工夫する
 *
 * c[i][j] := index`i`において、文字`j`が右側に現れる最小のindex
 * => あとは`j`を辞書順に（`a`:=(j=0)から順に）みていけばよい
*/
int main()
{
  int N, K;
  string S;
  cin >> N >> K >> S;

  vector<vector<int>> c(N+1, vector<int>(26));

  // 前処理（後ろから累積和）
  for (int j=0; j<26; j++) c[N][j] = N;
  for (int i=N-1; i>=0; i--) {
    for (int j=0; j<26; j++) {
      if ((int)(S[i] - 'a') == j) c[i][j] = i;
      else c[i][j] = c[i+1][j];
    }
  }

  string ans = "";
  int cur_pos = 0;
  for (int k=0; k<K; k++) {
    for (int j=0; j<26; j++) {
      if (N - c[cur_pos][j] >= K - k) {
        ans += (char)('a' + j);
        cur_pos = c[cur_pos][j] + 1;
        break;
      }
    }
  }

  cout << ans << endl;
}
