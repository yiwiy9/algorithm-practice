#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;

  vector<vector<int>> field(H, vector<int>(W));
  vector<int> cnt_list(N+1);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> field[i][j];
      if (i < h && j < w) continue;
      cnt_list[field[i][j]]++;
    }
  }

  vector<vector<int>> ans(H-h+1, vector<int>(W-w+1));
  for (int a=1; a<=N; a++) if (cnt_list[a] != 0) ans[0][0]++;

  for (int i=0; i+h-1<H; i++) {
    if (i%2 == 0) {
      // 下方向に移動
      if (i != 0) {
        for (int j=0; j<w; j++) {
          cnt_list[field[i-1][j]]++;
          cnt_list[field[i+h-1][j]]--;
        }
        for (int a=1; a<=N; a++) if (cnt_list[a] != 0) ans[i][0]++;
      }

      for (int j=1; j+w-1<W; j++) {
        // 右方向に移動
        for (int k=i; k<i+h; k++) {
          cnt_list[field[k][j-1]]++;
          cnt_list[field[k][j+w-1]]--;
        }
        for (int a=1; a<=N; a++) if (cnt_list[a] != 0) ans[i][j]++;
      }
    } else {
      // 下方向に移動
      for (int j=W-w; j<W; j++) {
        cnt_list[field[i-1][j]]++;
        cnt_list[field[i+h-1][j]]--;
      }
      for (int a=1; a<=N; a++) if (cnt_list[a] != 0) ans[i][W-w]++;

      for (int j=W-2; j-w+1>=0; j--) {
        // 左方向に移動
        for (int k=i; k<i+h; k++) {
          cnt_list[field[k][j+1]]++;
          cnt_list[field[k][j-w+1]]--;
        }
        for (int a=1; a<=N; a++) if (cnt_list[a] != 0) ans[i][j-w+1]++;
      }
    }
  }

  for (int i=0; i<=H-h; i++) {
    for (int j=0; j<=W-w; j++) {
      cout << ans[i][j];
      if (j != W-w) cout << ' ';
      else cout << endl;
    }
  }
}
