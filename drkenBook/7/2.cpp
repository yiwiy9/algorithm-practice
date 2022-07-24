#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Point = pair<long long, long long>;

/**
 * https://atcoder.jp/contests/abc091/tasks/arc092_a
 * https://drken1215.hatenablog.com/entry/2021/07/05/183800
 */
int main()
{
  int N;
  cin >> N;
  vector<Point> red(N), blue(N);
  for (int i=0; i<N; i++) cin >> red[i].first >> red[i].second;
  for (int i=0; i<N; i++) cin >> blue[i].first >> blue[i].second;

  // 青い点を x 座標が小さい順にソートする (デフォルトで第一引数の辞書順比較)
  sort(blue.begin(), blue.end());

  vector<bool> used_red(N, false);

  int ans = 0;
  for (int i=0; i<N; i++) {
    int max_y = -1, max_y_idx = -1;
    for (int j=0; j<N; j++) {
      if (used_red[j]) continue;

      if (red[j].first >= blue[i].first || red[j].second >= blue[i].second) continue;

      if (red[j].second > max_y) {
        max_y = red[j].second;
        max_y_idx = j;
      }
    }

    if (max_y_idx != -1) {
      used_red[max_y_idx] = true;
      ans++;
    }
  }

  cout << ans << endl;
}
