#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Point = pair<int, int>;
const Point INF = {-1, -1};

int H, W;
vector<vector<bool>> seen;
Point func(const vector<string> &field, Point p) {
  if (seen[p.first][p.second]) return INF;

  seen[p.first][p.second] = true;

  char move = field[p.first][p.second];
  if (move == 'U' && p.first != 0) {
    return func(field, {p.first-1, p.second});
  } else if (move == 'D' && p.first != H-1) {
    return func(field, {p.first+1, p.second});
  } else if (move == 'L' && p.second != 0) {
    return func(field, {p.first, p.second-1});
  } else if (move == 'R' && p.second != W-1) {
    return func(field, {p.first, p.second+1});
  } else {
    return p;
  }
}

int main()
{
  cin >> H >> W;

  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];

  seen.assign(H, vector<bool>(W, false));
  Point ans = func(field, {0, 0});

  if (ans == INF) cout << -1 << endl;
  else cout << ans.first+1 << ' ' << ans.second+1 << endl;
}
