#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<int>> field(H, vector<int>(W));
  vector<int> row_sum(H), line_sum(W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> field[i][j];
      row_sum[i] += field[i][j];
      line_sum[j] += field[i][j];
    }
  }

  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int ans = 0;
      ans += row_sum[i];
      ans += line_sum[j];
      ans -= field[i][j];
      cout << ans;
      if (j < W-1) cout << ' ';
      else cout << endl;
    }
  }
}
