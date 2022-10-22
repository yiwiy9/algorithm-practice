#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];

  vector<int> X(W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (field[i][j] == '#') X[j]++;
    }
  }

  for (int j=0; j<W; j++) {
    cout << X[j];
    if (j != W-1) cout << ' ';
    else cout << endl;
  }
}
