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

  vector<vector<int>> ans(h, vector<int>(w));
  for (int n=1; n<=N; n++) ans[0][0] += cnt_list[n];

  for (int i=0; i+h-1<=H; i++) {
    if (i%2 == 0) {
      if (i != 0) {
        for (int j=0; j<w; j++) {
          cnt_list[field[i-1][j]]++;
          cnt_list[field[i+h-1][j]]--;
        }
      }
      for (int j=1; j+w-1<=W; j++) {
        for (int k=i; k<i+h-1; k++) {
          cnt_list[field[k][j-1]]++;
          cnt_list[field[k][j+w-1]]--;
        }
        for (int n=1; n<=N; n++) ans[i][j] += cnt_list[n];
      }
    } else {
      for (int j=W-1; j>W-w-1; j--) {
        cnt_list[field[i-1][j]]++;
        cnt_list[field[i+h-1][j]]--;
      }
      for (int j=W-2; j-w+1>=0; j--) {
        for (int k=i; k<i+h-1; k++) {
          cnt_list[field[k][j+1]]++;
          cnt_list[field[k][j-w+1]]--;
        }
        for (int n=1; n<=N; n++) ans[i][j] += cnt_list[n];
      }
    }
  }

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cout << ans[i][j];
      if (j != w-1) cout << ' ';
      else cout << endl;
    }
  }
}
