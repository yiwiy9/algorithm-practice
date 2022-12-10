#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;

/**
 * https://atcoder.jp/contests/typical90/tasks/typical90_w
 * https://twitter.com/e869120/status/1386138990361726978/photo/1
 *
 * bit全探索
*/
// int main()
// {
//   int H, W;
//   cin >> H >> W;

//   vector<string> field(H);
//   for (int i=0; i<H; i++) cin >> field[i];

//   int ans = 0;
//   for (int bit=0; bit<(1 << (H*W)); bit++) {
//     bool ok = true;
//     vector<vector<bool>> is_king_field(H, vector<bool>(W, false));
//     for (int i=0; i<(H*W); i++) {
//       if ((bit & (1 << i)) == 0) continue;

//       int h = i / W;
//       int w = i % W;

//       // 黒
//       if (field[h][w] == '#') ok = false;
//       // 左
//       if (w-1>=0 && is_king_field[h][w-1]) ok = false;
//       // 左上
//       if (w-1>=0 && h-1>=0 && is_king_field[h-1][w-1]) ok = false;
//       // 上
//       if (h-1>=0 && is_king_field[h-1][w]) ok = false;
//       // 右上
//       if (w+1<W && h-1>=0 && is_king_field[h-1][w+1]) ok = false;

//       is_king_field[h][w] = true;
//     }

//     if (ok) {
//       ans++;
//       ans %= MOD;
//     }
//   }

//   cout << ans << endl;
// }

/**
 * https://twitter.com/e869120/status/1386138990361726978/photo/2
 *
 * bitDP
 * dp[h][bit] := 一行目の状態がbitであった場合のh行目の通り数
*/
int main()
{
  int H, W;
  cin >> H >> W;

  vector<int> field(H);
  for (int i=0; i<H; i++) {
    string row;
    cin >> row;

    for (int j=0; j<W; j++) {
      if (row[j] == '#') {
        field[i] += (1<<j);
      }
    }
  }

  vector<vector<int>> dp(H+1, vector<int>(1<<W, 0));
  dp[0][0] = 1;

  for (int h=0; h<H; h++) {
    for (int current_bit=0; current_bit<(1 << W); current_bit++) {
      if (dp[h][current_bit] == 0) continue;

      for (int next_bit=0; next_bit<(1 << W); next_bit++) {
        // 黒
        if (next_bit & field[h]) continue;

        // 縦・斜め
        if (current_bit & next_bit) continue;
        if ((current_bit << 1) & next_bit) continue;
        if ((current_bit >> 1) & next_bit) continue;

        // 横
        if ((next_bit << 1) & next_bit) continue;
        if ((next_bit >> 1) & next_bit) continue;

        dp[h+1][next_bit] += dp[h][current_bit];
        dp[h+1][next_bit] %= MOD;
      }
    }
  }

  int ans = 0;
  for (int bit=0; bit<(1 << W); bit++) {
    ans += dp[H][bit];
    ans %= MOD;
  }

  cout << ans << endl;
}
