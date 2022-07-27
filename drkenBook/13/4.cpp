#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

using Point = pair<int, int>; // {height, width}

const vector<Point> MOVE = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int H, W;
bool is_valid_point(Point v, Point move) {
  return v.first+move.first>=0 && v.first+move.first<H && v.second+move.second>=0 && v.second+move.second<W;
}

/**
 * 1 行目に迷路のサイズ (縦の長さ, 横の長さ)
 * 2 行目以降に迷路の地図 (S: スタート, G: ゴール, .: 通路, #: 壁)
 */
int main()
{
  cin >> H >> W;

  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];

  // スタートとゴールの位置
  Point s = {-1, -1}, g = {-1, -1};
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (field[i][j] == 'S') s = {i, j};
      if (field[i][j] == 'G') g = {i, j};
    }
  }

  queue<Point> que;
  vector<vector<int>> dist(H, vector<int>(W, -1));

  // 始点をキューに入れる
  dist[s.first][s.second] = 0;
  que.push(s);

  while (!que.empty()) {
    Point v = que.front();
    que.pop();

    for (auto move : MOVE) {
      if (!is_valid_point(v, move)) continue;

      Point next_v = {v.first + move.first, v.second + move.second};
      if (dist[next_v.first][next_v.second] != -1) continue;

      if (field[next_v.first][next_v.second] == '#') continue;

      dist[next_v.first][next_v.second] = dist[v.first][v.second] + 1;
      que.push(next_v);
    }
  }

  cout << dist[g.first][g.second] << endl;
}
