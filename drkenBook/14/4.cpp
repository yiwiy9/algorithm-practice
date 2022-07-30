#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int INF = 1 << 30;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

using Node = pair<int, int>; // {height, width}

/**
 * https://atcoder.jp/contests/arc005/tasks/arc005_3
 * '#'への移動を重み１の辺、'.'への移動を重み０の辺と捉えてダイクストラ
 *
 * グラフの各辺の重みが 0 or 1なので、0-1 BFS（O(|V|+|E|)）が使える
 * → priority_queueではなくて、両端キュー deque を使う（キューの中身例：001111）
 *   参考：https://drken1215.hatenablog.com/entry/2021/07/30/024800
 */
int main()
{
  int H, W;
  cin >> H >> W;

  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];

  // スタートとゴールの位置
  int sx = -1, sy = -1, gx = -1, gy = -1;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (field[i][j] == 's') sx = i, sy = j;
      if (field[i][j] == 'g') gx = i, gy = j;
    }
  }

  vector<vector<int>> dist(H, vector<int>(W, INF));
  priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>> que;

  // 始点
  dist[sx][sy] = 0;
  que.push({0, {sx, sy}});

  while (!que.empty()) {
    auto [d, v] = que.top();
    auto [x, y] = v;
    que.pop();

    // ゴミの除去
    if (d > dist[x][y]) continue;

    for (int dir=0; dir<4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

      if (field[nx][ny] == '#') {
        if (chmin(dist[nx][ny], dist[x][y] + 1)) {
          que.push({dist[nx][ny], {nx, ny}});
        }
      } else {
        if (chmin(dist[nx][ny], dist[x][y])) {
          que.push({dist[nx][ny], {nx, ny}});
        }
      }
    }
  }

  if (dist[gx][gy] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}
