#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<int> DX = {1, 0, 1, -1};
const vector<int> DY = {0, 1, 1, 1};
int N;
vector<string> a;

bool calc(int x, int y, int dx, int dy)
{
  int count = 0;
  for (int i=0; i<6; i++) {
    if (min(x, y) < 0 || max(x, y) > N-1) return false;
    if (a[x][y] == '#') count++;
    x += dx;
    y += dy;
  }
  return count >= 4;
}

/**
 * https://atcoder.jp/contests/abc241/tasks/abc241_c
 *
 * pair とか使わない、sting自体が配列的には使える
 * シンプルに全探索をすればよいだけ
 */
int main()
{
  cin >> N;
  string str;
  for (int i=0; i<N; i++) {
    cin >> str;
    a.push_back(str);
  }

  bool ok = false;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      for (int k=0; k<4; k++)
      {
        if (calc(i, j, DX[k], DY[k])) ok = true;
      }
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
