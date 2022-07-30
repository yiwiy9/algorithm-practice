#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;

const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// 帰りがけ順で足していく
int H, W;
vector<vector<int>> dp;
int dfs(const vector<string> &field, int x, int y)
{
  // すでに探索済みの場合、以後の遷移数のMAXを返す
  if (dp[x][y] != -1) return dp[x][y];

  // ゴールの場合
  if (x==H-1 && y==W-1) return 1;

  int sum = 0;
  for (int dir=0; dir<2; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx >= H || ny >= W) continue;

    if (field[nx][ny] == '#') continue;

    sum += dfs(field, nx, ny);
    sum %= MOD;
  }

  return dp[x][y] = sum;
}

int main()
{
  cin >> H >> W;

  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];

  dp.assign(H, vector<int>(W, -1));

  dfs(field, 0, 0);

  cout << dp[0][0] << endl;
}
