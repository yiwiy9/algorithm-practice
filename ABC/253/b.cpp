#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

using Point = pair<int, int>;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> S(H);

  for (int i=0; i<H; i++) cin >> S[i];

  vector<Point> koma;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (S[i][j] == 'o') {
        koma.push_back({i,j});
      }
    }
  }

  int ans = 0;
  ans += abs(koma[0].first - koma[1].first);
  ans += abs(koma[0].second - koma[1].second);

  cout << ans << endl;
}
